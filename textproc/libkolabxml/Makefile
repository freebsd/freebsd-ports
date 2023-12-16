PORTNAME=	libkolabxml
DISTVERSION=	1.2.1-3
DISTVERSIONSUFFIX=	-g27d1927
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/kde/${PORTNAME}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kolab XML Format Schema Definitions Library
WWW=		https://kolab.org/

# The XSD schemas in schemas/ are APACHE20-licensed, and some files
# are in public domain. The library itself and the installed headers
# are considered LGPL3-licensed, though.
LICENSE=	LGPL3+

BUILD_DEPENDS=	libxsd>=4.2.0:devel/libxsd \
		xsdcxx:devel/xsd
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libxerces-c.so.3:textproc/xerces-c3

USES=		cmake tar:xz
USE_LDCONFIG=	yes

# TODO: Conditionally enable the bindings based on OPTIONs.
CMAKE_OFF=	BUILD_TESTS \
		BUILD_UTILS \
		CSHARP_BINDINGS \
		DIST_ONLY \
		JAVA_BINDINGS \
		PHP_BINDINGS \
		PYTHON_BINDINGS

PLIST_SUB=	SHLIB_VER=${PORTVERSION:R}

create-distfile:
	${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	${SH} ${FILESDIR}/create_libkolabxml_release.sh \
		${DISTDIR}/${DIST_SUBDIR} \
		${DISTVERSIONFULL}

.include <bsd.port.mk>
