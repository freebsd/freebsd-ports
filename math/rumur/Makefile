PORTNAME=	rumur
DISTVERSIONPREFIX=	v
DISTVERSION=	2023.11.27
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Model checker, a formal verification tool for state machines
WWW=		https://github.com/Smattr/rumur

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmpxx.so:math/gmp

USES=		bison cmake compiler:c++11-lang python:build shebangfix
USE_LDCONFIG=	yes

SHEBANG_FILES=	rumur/src/rumur-run
SHEBANG_GLOB=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	Smattr

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	BISON_EXECUTABLE:STRING=${LOCALBASE}/bin/bison

BINARY_ALIAS=	python3=${PYTHON_CMD}

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} --build . --target check

.include <bsd.port.mk>
