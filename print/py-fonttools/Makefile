PORTNAME=	fonttools
PORTVERSION=	4.59.0
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source library for manipulating fonts, written in Python
WWW=		https://github.com/fonttools/fonttools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ufolib2>=0:print/py-ufolib2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517

OPTIONS_DEFINE=	GRAPHITE INTERPOLATABLE LXML PLOT REPACKER SYMFONT UNICODE WOFF
OPTIONS_DEFAULT=LXML UNICODE WOFF
GRAPHITE_DESC=	Process graphite type tables in ttLib/tables
INTERPOLATABLE_DESC=	Interpolatability support
LXML_DESC=	Read/write XML files via lxml (faster/safer than built-in ElementTree)
PLOT_DESC=	Visualize DesignSpaceDocument and resulting VariationModel
REPACKER_DESC=	Pack GSUB/GPOS tables with harfbuzz repacker
SYMFONT_DESC=	Symbolic font statistics analysis
UNICODE_DESC=	Use latest Unicode Character Database
WOFF_DESC=	Compress/uncompress WOFF webfonts

GRAPHITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lz4>=1.7.4.2:archivers/py-lz4@${PY_FLAVOR}
INTERPOLATABLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}scipy>=0:science/py-scipy@${PY_FLAVOR}
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml5>=4.0:devel/py-lxml5@${PY_FLAVOR}
PLOT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}
REPACKER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uharfbuzz>=0.23.0:print/py-uharfbuzz@${PY_FLAVOR}
SYMFONT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>=0:math/py-sympy@${PY_FLAVOR}
WOFF_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>=1.0.1:archivers/py-brotli@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}zopfli>=0.1.4:archivers/py-zopfli@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:UNICODE} && ${PYTHON_REL} < 31300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}unicodedata2>=15.1.0:devel/py-unicodedata2@${PY_FLAVOR}
.endif

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
