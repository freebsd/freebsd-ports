PORTNAME=	yaz++
DISTVERSION=	1.9.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://ftp.indexdata.dk/pub/yazpp/
DISTNAME=	yazpp-${DISTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	C++ toolkit for development of Z39.50v3 clients and servers
WWW=		https://www.indexdata.dk/yazplusplus/

LIB_DEPENDS=	libyaz.so:net/yaz

USES=		gnome libtool pathfix pkgconfig
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes

LDFLAGS+=	-Wl,--as-needed

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
