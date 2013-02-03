# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libkolabxml
PORTVERSION=	0.8.1
CATEGORIES=	textproc
MASTER_SITES=	http://mirror.kolabsys.com/pub/releases/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kolab XML Format Schema Definitions Library

# The XSD schemas in schemas/ are AL2-licensed, and some files are
# in public domain. The library itself and the installed headers are
# considered LGPL3-licensed, though.
LICENSE=	LGPL3

BUILD_DEPENDS=	xsdcxx:${PORTSDIR}/devel/xsd
LIB_DEPENDS=	boost_system:${PORTSDIR}/devel/boost-libs \
		curl:${PORTSDIR}/ftp/curl \
		xerces-c.3:${PORTSDIR}/textproc/xerces-c3

# TODO: Conditionally enable the bindings based on OPTIONs.
CMAKE_ARGS=	-DBUILD_TESTS:BOOL=OFF \
		-DCSHARP_BINDINGS:BOOL=OFF \
		-DDIST_ONLY:BOOL=OFF \
		-DJAVA_BINDINGS:BOOL=OFF \
		-DPHP_BINDINGS:BOOL=OFF \
		-DPYTHON_BINDINGS:BOOL=OFF
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
