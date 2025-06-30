PORTNAME=	yazproxy
DISTVERSION=	1.3.13
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://ftp.indexdata.dk/pub/yazproxy/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Powerful general purpose Z39.50/SRW/SRU proxy
WWW=		https://www.indexdata.dk/yazproxy/

LIB_DEPENDS=	libyaz.so:net/yaz \
		libyazpp.so:net/yaz++

USES=		gnome libtool
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
