PORTNAME=	director
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Define and run multi-jail environments with AppJail
WWW=		https://github.com/DtxdF/${PORTNAME}

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}strictyaml>=0:devel/py-strictyaml@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	APPJAIL_STABLE
OPTIONS_SINGLE=		APPJAIL
OPTIONS_SINGLE_APPJAIL=	APPJAIL_DEVEL APPJAIL_STABLE

APPJAIL_DEVEL_DESC=	Use the development version of AppJail
APPJAIL_STABLE_DESC=	Use the stable version of AppJail

APPJAIL_DEVEL_RUN_DEPENDS=	appjail:sysutils/appjail-devel
APPJAIL_STABLE_RUN_DEPENDS=	appjail:sysutils/appjail

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
