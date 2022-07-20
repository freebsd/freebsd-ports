PORTNAME=	mod_authnz_external
PORTVERSION=	3.3.2
CATEGORIES=	www
MASTER_SITES=	http://zhegan.in/files/
PKGNAMESUFFIX=	24
DIST_SUBDIR=	apache24

MAINTAINER=	eugene@zhegan.in
COMMENT=	Allows users authentication based on external mechanisms on apache 2.4

LICENSE=	APACHE20

USES=		apache:2.4 cpe
CPE_VENDOR=	${PORTNAME}_project
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SHORTMODNAME=	authnz_external

PORTDOCS=	AUTHENTICATORS INSTALL README	\
		CHANGES UPGRADE INSTALL.HARDCODE

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
