PORTNAME=	castget
DISTVERSION=	2.0.1-20220211
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line podcast downloader
WWW=		https://castget.johndal.com/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	ronn:textproc/rubygem-ronn
LIB_DEPENDS=	libtag.so:audio/taglib \
		libcurl.so:ftp/curl

USES=		autoreconf compiler:c11 gmake gnome groff libtool \
		localbase:ldflags pkgconfig
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mlj
GH_TAGNAME=	da9727d

#CONFIGURE_ARGS=	--disable-static
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/castget \
		share/man/man1/castget.1.gz share/man/man5/castgetrc.5.gz

.include <bsd.port.mk>
