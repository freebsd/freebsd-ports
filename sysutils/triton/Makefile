# $FreeBSD$

PORTNAME=	triton
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dynamic Binary Analysis (DBA) framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libcapstone.so:devel/capstone4 \
		libz3.so:math/z3

USES=		cmake compiler:c++11-lang python:build shebangfix
SHEBANG_FILES=	src/scripts/extract_syscall.py
USE_GITHUB=	yes
GH_ACCOUNT=	JonathanSalwan
GH_PROJECT=	Triton
USE_LDCONFIG=	yes

CMAKE_OFF=	PYTHON_BINDINGS

.include <bsd.port.mk>
