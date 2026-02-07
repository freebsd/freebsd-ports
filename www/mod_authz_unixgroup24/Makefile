PORTNAME=	mod_authz_unixgroup
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.1.0
CATEGORIES=	www
PKGNAMESUFFIX=	24
DIST_SUBDIR=	apache24

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Allows users authentication based on UNIX group on apache 2.4
WWW=		https://github.com/phokz/mod-auth-external/wiki/ModAuthzUnixGroup

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		apache cpe
USE_GITHUB=	yes
GH_ACCOUNT=	phokz
GH_PROJECT=	mod-auth-external
CPE_VENDOR=	${GH_PROJECT}_project
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SHORTMODNAME=	authz_unixgroup

PORTDOCS=	CHANGES INSTALL NOTICE README

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
