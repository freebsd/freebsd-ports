PORTNAME=	castxml
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.13
CATEGORIES=	textproc devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C-family Abstract Syntax Tree XML Output
WWW=		https://github.com/CastXML/CastXML

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${LOCALBASE}/lib/libxml2.so:textproc/libxml2

USES=		cmake:testing compiler:c++11-lang llvm:19,lib # fails to build with llvm-17: https://github.com/CastXML/CastXML/issues/270

USE_GITHUB=	yes
GH_ACCOUNT=	CastXML
GH_PROJECT=	CastXML

CMAKE_ARGS=	-DLLVM_DIR:STRING=${LOCALBASE}/llvm${LLVM_VERSION}/lib/cmake/llvm \
		-DCastXML_INSTALL_MAN_DIR=share/man

OPTIONS_DEFINE=		DOCS
OPTIONS_SUB=		yes

DOCS_CMAKE_BOOL=	SPHINX_MAN
DOCS_CMAKE_ON=		-DSPHINX_EXECUTABLE=${LOCALBASE}/bin/sphinx-build
DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/sphinx-build:textproc/py-sphinx

post-stage: # autoplist: plist changes with llvm versions
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l | ${SED} 's|castxml\.1|castxml.1.gz|' > ${TMPPLIST}

do-test: # many tests fail, see https://github.com/CastXML/CastXML/issues/245
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

# tests as of 0.6.13: 100% tests passed, 0 tests failed out of 4392

.include <bsd.port.mk>
