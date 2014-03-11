# Created by: Eugene M. Kim <ab@astralblue.net>
# $FreeBSD$

PORTNAME=	spamass-milter
PORTVERSION=	0.3.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	spamass-milt

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Sendmail Milter (mail filter) plugin for SpamAssassin

BUILD_DEPENDS=	spamc:${PORTSDIR}/mail/spamassassin
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	GPLv2


OPTIONS_DEFINE=	ADDAUTH_PATCH REJECTTEXT_PATCH LDAP SENDMAIL_PORT IPV6
ADDAUTH_PATCH_DESC=	Bypass checks for SMTP AUTH connections
REJECTTEXT_PATCH_DESC=	Customize SMTP reject message
SENDMAIL_PORT_DESC=	Build against sendmail port

NO_STAGE=	yes
.include <bsd.port.pre.mk>

ORIG_ARGS=	fd:mMp:P:r:u:D:i:b:B:e:x
NEW_ARGS:=	${ORIG_ARGS}

.if ${PORT_OPTIONS:MADDAUTH_PATCH}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-addauth
NEW_ARGS:=	${NEW_ARGS}a
.endif

.if ${PORT_OPTIONS:MREJECTTEXT_PATCH}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-rejecttext1
NEW_ARGS:=	${NEW_ARGS}R:
.endif

.if ${PORT_OPTIONS:MIPV6}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-ipv6
.endif

# extra-patch-options is modified in pre-patch
.if ${ORIG_ARGS} != ${NEW_ARGS}
EXTRA_PATCHES+=	${WRKDIR}/extra-patch-options
.endif

.if exists(${LOCALBASE}/lib/libldap.so)
WITH_LDAP=yes
.undef WITHOUT_LDAP
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
.endif

USE_RC_SUBR=	spamass-milter
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

MAN1=		spamass-milter.1

pre-patch:
.if ${ORIG_ARGS} != ${NEW_ARGS}
	@${SED} -e 's|%NEW_ARGS%|${NEW_ARGS}|' ${FILESDIR}/extra-patch-options > ${WRKDIR}/extra-patch-options
.endif

post-patch:
	@${SED} -e's,%%PREFIX%%,${PREFIX},g' \
		${FILESDIR}/activation.txt > ${WRKDIR}/activation.txt
.if ${PORT_OPTIONS:MLDAP} && ${PORT_OPTIONS:MLDAP}
	@${REINPLACE_CMD} -e 's|-lmilter|-lmilter -lldap|g' ${WRKSRC}/configure
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/activation.txt ${DOCSDIR}/activation.txt
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.include <bsd.port.post.mk>
