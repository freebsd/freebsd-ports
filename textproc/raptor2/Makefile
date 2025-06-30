PORTNAME=	raptor2
DISTVERSION=	2.0.16
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	https://download.librdf.org/source/

PATCH_SITES=	https://github.com/dajobe/raptor/commit/
PATCHFILES=	4dbc4c1da2a033c497d84a1291c46f416a9cac51.patch:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	RDF Parser Toolkit for Redland
WWW=		https://librdf.org/raptor/

# Even though GPLv3 is not explicitly mentioned in the port's LICENSE.html, one
# of its licenses is "GPLv2 or newer", which includes GPLv3.
LICENSE=	APACHE20 GPLv2 GPLv3 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libicuuc.so:devel/icu \
		libyajl.so:devel/yajl

CONFLICTS=	raptor-1.4.1[0-9]* raptor-1.4.21

USES=		gnome libtool:keepla localbase pathfix pkgconfig
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
