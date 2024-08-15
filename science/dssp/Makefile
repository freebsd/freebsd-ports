PORTNAME=	dssp
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.2
PORTREVISION=	1
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

USES=		cmake:noninja,testing compiler:c++17-lang # ninja breaks when mrc is present
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	PDB-REDO

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	ENABLE_TESTING

.include <bsd.port.mk>
