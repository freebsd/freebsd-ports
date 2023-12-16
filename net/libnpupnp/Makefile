PORTNAME=	libnpupnp
DISTVERSION=	5.1.2
CATEGORIES=	net
MASTER_SITES=	https://www.lesbonscomptes.com/upmpdcli/downloads/

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	C++ base UPnP library, derived from Portable UPnP, a.k.a libupnp
WWW=		https://www.lesbonscomptes.com/upmpdcli/npupnp-doc/libnpupnp.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libmicrohttpd.so:www/libmicrohttpd

USES=		compiler:c++17-lang libtool localbase pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
