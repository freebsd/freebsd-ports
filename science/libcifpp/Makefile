PORTNAME=	libcifpp
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to manipulate mmCIF and PDB files
WWW=		https://github.com/PDB-REDO/libcifpp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs

USES=		cmake:testing compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	PDB-REDO

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	CIFPP_BUILD_TESTS

.include <bsd.port.mk>
