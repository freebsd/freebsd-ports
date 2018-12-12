# $FreeBSD$

PORTNAME=	rmf
DISTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	science graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to support reading and writing of Rich Molecular Format files

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libhdf5.so:science/hdf5 \
		libsz.so:science/szip

USES=		compiler:c++11-lang cmake:outsource python:build shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	salilab
GH_TAGNAME=	f917cf2
SHEBANG_GLOB=	*.py
USE_LDCONFIG=	yes

BINARY_ALIAS=	python=${PYTHON_CMD}

.include <bsd.port.mk>
