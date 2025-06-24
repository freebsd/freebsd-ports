PORTNAME=	director
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Define and run multi-jail environments with AppJail
WWW=		https://github.com/DtxdF/${PORTNAME}

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml-env>=0:devel/py-pyaml-env@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
