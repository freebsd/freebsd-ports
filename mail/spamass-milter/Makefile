# Created by: Eugene M. Kim <ab@astralblue.net>
# $FreeBSD$

PORTNAME=	spamass-milter
PORTVERSION=	0.4.0
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	SAVANNAH/spamass-milt

MAINTAINER=	bmah@FreeBSD.org
COMMENT=	Sendmail Milter (mail filter) plugin for SpamAssassin

BUILD_DEPENDS=	spamc:mail/spamassassin
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	GPLv2

OPTIONS_DEFINE=	LDAP MILTER_PORT DOCS
MILTER_PORT_DESC=	Build against libmilter port

.include <bsd.port.pre.mk>

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

post-patch:
	@${SED} -e's,%%PREFIX%%,${PREFIX},g' \
		${FILESDIR}/activation.txt > ${WRKDIR}/activation.txt
.if ${PORT_OPTIONS:MLDAP} && ${PORT_OPTIONS:MLDAP}
	@${REINPLACE_CMD} -e 's|-lmilter|-lmilter -lldap|g' ${WRKSRC}/configure
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/activation.txt ${STAGEDIR}${DOCSDIR}/activation.txt
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"
.include <bsd.port.post.mk>
