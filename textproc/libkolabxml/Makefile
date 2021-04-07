PORTNAME=	libkolabxml
PORTVERSION=	1.1.6
PORTREVISION=	12
CATEGORIES=	textproc
MASTER_SITES=	http://mirror.kolabsys.com/pub/releases/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kolab XML Format Schema Definitions Library

# The XSD schemas in schemas/ are APACHE20-licensed, and some files
# are in public domain. The library itself and the installed headers
# are considered LGPL3-licensed, though.
LICENSE=	LGPL3

BUILD_DEPENDS=	xsdcxx:devel/xsd
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libxerces-c.so.3:textproc/xerces-c3

# TODO: Conditionally enable the bindings based on OPTIONs.
CMAKE_OFF=	BUILD_TESTS \
		BUILD_UTILS \
		CSHARP_BINDINGS \
		DIST_ONLY \
		JAVA_BINDINGS \
		PHP_BINDINGS \
		PYTHON_BINDINGS
USES=		cmake
USE_LDCONFIG=	yes

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

.include <bsd.port.mk>
