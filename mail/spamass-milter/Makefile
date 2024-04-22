PORTNAME=	spamass-milter
PORTVERSION=	0.4.0
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	SAVANNAH/spamass-milt

MAINTAINER=	bmah@FreeBSD.org
COMMENT=	Sendmail Milter (mail filter) plugin for SpamAssassin
WWW=		https://savannah.nongnu.org/projects/spamass-milt/

LICENSE=	GPLv2

BUILD_DEPENDS=	spamc:mail/spamassassin
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_RC_SUBR=	spamass-milter

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	LDAP MILTER_PORT DOCS
MILTER_PORT_DESC=	Build against libmilter port

LDAP_USES=	ldap localbase:ldflags

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libldap.so)
WITH_LDAP=yes
.undef WITHOUT_LDAP
.endif

post-patch:
	@${SED} -e's,%%PREFIX%%,${PREFIX},g' \
		${FILESDIR}/activation.txt > ${WRKDIR}/activation.txt

post-patch-LDAP-on:
	@${REINPLACE_CMD} -e 's|-lmilter|-lmilter -lldap|g' ${WRKSRC}/configure

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/activation.txt ${STAGEDIR}${DOCSDIR}/activation.txt
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"
.include <bsd.port.post.mk>
