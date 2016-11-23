# $FreeBSD$

PORTNAME=	cryptominisat
PORTVERSION=	5.0.1
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	6yearold@gmail.com
COMMENT=	General-purpose award-winning SAT solver

LICENSE=	MIT LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE-SCALMC

BUILD_DEPENDS=	xxd:editors/vim-lite # for xxd tool
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	msoos

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DNOM4RI=1 -DENABLE_PYTHON_INTERFACE=OFF

.include <bsd.port.mk>
