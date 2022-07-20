PORTNAME=	castget
DISTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line podcast downloader

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libid3.so:audio/id3lib \
		libcurl.so:ftp/curl

USES=		compiler:c11 gnome libtool localbase:ldflags pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_GNOME=	glib20 libxml2
# CONFIGURE_ARGS=	--disable-static
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/castget \
		man/man1/castget.1.gz man/man5/castgetrc.5.gz

.include <bsd.port.mk>
