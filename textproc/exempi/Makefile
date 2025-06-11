PORTNAME=	exempi
DISTVERSION=	2.6.6
CATEGORIES=	textproc
MASTER_SITES=	https://libopenraw.freedesktop.org/download/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Port of Adobe XMP SDK to work on UNIX
WWW=		https://libopenraw.freedesktop.org/exempi/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs
LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		cpe compiler:c++11-lang gmake iconv libtool localbase \
		pathfix tar:xz
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
USE_CXXSTD=	c++11

.include <bsd.port.mk>
