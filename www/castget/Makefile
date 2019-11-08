# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	castget
DISTVERSION=	2.0.1
CATEGORIES=	www
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line podcast downloader

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libid3.so:audio/id3lib \
		libcurl.so:ftp/curl

USE_LDCONFIG=	yes
USES=		gnome libtool pkgconfig tar:bzip2
USE_GNOME=	glib20 libxml2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
# CONFIGURE_ARGS=	--disable-static
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/castget \
		man/man1/castget.1.gz man/man5/castgetrc.5.gz

.include <bsd.port.mk>
