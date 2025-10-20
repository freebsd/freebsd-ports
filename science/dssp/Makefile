PORTNAME=	dssp
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.11
PORTREVISION=	2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Application to assign secondary structure to proteins
WWW=		https://github.com/PDB-REDO/dssp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libmcfp>0:devel/libmcfp \
		mrc:devel/mrc
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libcifpp.so:science/libcifpp
TEST_DEPENDS=	catch2>0:devel/catch2

USES=		cmake:noninja,testing compiler:c++17-lang # ninja breaks when mrc is present
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	PDB-REDO

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

# tests as of 4.4.11: 100% tests passed, 0 tests failed out of 1

.include <bsd.port.mk>
