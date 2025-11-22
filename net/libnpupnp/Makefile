PORTNAME=	libnpupnp
DISTVERSION=	6.2.3
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

USES=		compiler:c++17-lang localbase:ldflags meson pkgconfig
USE_LDCONFIG=	yes

MESON_ARGS=	-Dunspecified_server=false \
		-Dtestmains=false

.include <bsd.port.mk>
