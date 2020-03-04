# $FreeBSD$

PORTNAME=	cryptominisat
DISTVERSION=	5.6.8
PORTREVISION=	5
CATEGORIES=	math

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	General-purpose award-winning SAT solver

LICENSE=	MIT LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	msoos

CMAKE_ON=	NOM4RI
CMAKE_OFF=	ENABLE_PYTHON_INTERFACE

.include <bsd.port.mk>
