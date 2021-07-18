PORTNAME=	kfr
DISTVERSION=	4.2.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ DSP framework, FFT, Sample Rate Conversion, FIR/IIR/Biquad Filters

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	kfrlib

CMAKE_ON=	BUILD_SHARED_LIBS

do-test: # some tests fail: https://github.com/kfrlib/kfr/issues/132
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_SHARED_LIBS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${BUILD_WRKSRC}/bin/all_tests

.include <bsd.port.mk>
