# New ports collection makefile for:   spamass-milter
# Date created:        29 April 2002
# Whom:                Eugene M. Kim <ab@astralblue.net>
#
# $FreeBSD$
#

PORTNAME=	spamass-milter
PORTVERSION=	0.3.1
PORTREVISION=	11
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	spamass-milt

MAINTAINER=	michael@fun-box.ru
COMMENT=	Sendmail Milter (mail filter) plugin for SpamAssassin

BUILD_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	GPLv2

MAKE_JOBS_SAFE=	yes

OPTIONS=	ADDAUTH_PATCH "Bypass checks for SMTP AUTH connections" off \
		REJECTTEXT_PATCH "Customize SMTP reject message" off \
		LDAP "LDAP support" off \
		SENDMAIL_PORT "Build against sendmail port" off

.include <bsd.port.pre.mk>

ORIG_ARGS=	fd:mMp:P:r:u:D:i:b:B:e:x
NEW_ARGS:=	${ORIG_ARGS}

.if defined(WITH_ADDAUTH_PATCH)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-addauth
NEW_ARGS:=	${NEW_ARGS}a
.endif

.if defined(WITH_REJECTTEXT_PATCH)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-rejecttext1
NEW_ARGS:=	${NEW_ARGS}R:
.endif

# extra-patch-options is modified in pre-patch
.if ${ORIG_ARGS} != ${NEW_ARGS}
EXTRA_PATCHES+=	${WRKDIR}/extra-patch-options
.endif

.if exists(${LOCALBASE}/lib/libldap.so)
WITH_LDAP=yes
.undef WITHOUT_LDAP
.endif

.if !defined(WITHOUT_LDAP) && defined(WITH_LDAP)
USE_OPENLDAP=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
.endif

USE_RC_SUBR=	spamass-milter
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

SUB_FILES=	pkg-message

MAN1=		spamass-milter.1

pre-patch:
.if ${ORIG_ARGS} != ${NEW_ARGS}
	@${SED} -e 's|%NEW_ARGS%|${NEW_ARGS}|' ${FILESDIR}/extra-patch-options > ${WRKDIR}/extra-patch-options
.endif

post-patch:
	@${SED} -e's,%%PREFIX%%,${PREFIX},g' \
		${FILESDIR}/activation.txt > ${WRKDIR}/activation.txt
.if !defined(WITHOUT_LDAP) && defined(WITH_LDAP)
	@${REINPLACE_CMD} -e 's|-lmilter|-lmilter -lldap|g' ${WRKSRC}/configure
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/activation.txt ${DOCSDIR}/activation.txt
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.include <bsd.port.post.mk>
