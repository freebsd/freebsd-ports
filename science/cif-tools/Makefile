PORTNAME=	cif-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.12 # chemistry
PORTREVISION=	5
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Suite of programs to manipulate and examine mmCIF files
WWW=		https://github.com/PDB-REDO/cif-tools

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libmcfp>0:devel/libmcfp \
		mrc:devel/mrc
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libcifpp.so:science/libcifpp

USES=		cmake:noninja compiler:c++17-lang # ninja: error: build.ninja:890: multiple rules generate ALL

USE_GITHUB=	yes
GH_ACCOUNT=	PDB-REDO

.include <bsd.port.mk>
