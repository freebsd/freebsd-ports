PORTNAME=	dssp
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.5
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Application to assign secondary structure to proteins
WWW=		https://github.com/PDB-REDO/dssp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mrc:devel/mrc
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libcifpp.so:science/libcifpp

USES=		cmake:noninja compiler:c++17-lang # ninja breaks when mrc is present

USE_GITHUB=	yes
GH_ACCOUNT=	PDB-REDO

PLIST_FILES=	bin/mkdssp \
		share/man/man1/mkdssp.1.gz

.include <bsd.port.mk>
