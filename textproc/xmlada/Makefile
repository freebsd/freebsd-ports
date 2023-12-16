PORTNAME=	xmlada
DISTVERSIONPREFIX=v
DISTVERSION=	24.0.0
CATEGORIES=	textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adacore XML suite for the Ada language
WWW=		https://github.com/AdaCore/xmlada

LICENSE=	GPLv3RLE

BUILD_DEPENDS=	gprbuild>=24:devel/gprbuild

USES=		ada:12,run gmake
USE_BINUTILS=	yes
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
GH_PROJECT=	xmlada

MAKE_ARGS+=	PROCESSORS=${MAKE_JOBS_NUMBER} \
		LIBVER=${PORTVERSION}
TEST_TARGET=	test
TEST_ENV+=	GPR_PROJECT_PATH=${PREFIX}/share/gpr	\
		PATH=${LOCALBASE}/gnat12/bin:${PATH}

OPTIONS_DEFINE=	DOCS EXAMPLES
PORTDOCS=	*
PORTEXAMPLES=	*

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx	\
		${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}
DOCS_USES=	python:build

do-build-DOCS-on:
	(cd ${WRKSRC}/docs && ${DO_MAKE_BUILD} html )

post-install:
	(cd ${STAGEDIR}${PREFIX}/lib/ && \
		${STRIP_CMD} libxmlada* )

post-install-DOCS-on:
	${RM} ${STAGEDIR}${DOCSDIR}/.buildinfo

.include <bsd.port.mk>
