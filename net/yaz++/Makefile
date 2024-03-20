PORTNAME=	yaz++
PORTVERSION=	1.6.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yazpp/
DISTNAME=	yazpp-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	C++ toolkit for development of Z39.50v3 clients and servers
WWW=		https://www.indexdata.dk/yazplusplus/

LIB_DEPENDS=	libyaz.so:net/yaz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-yaz=${LOCALBASE}/bin
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	yes

.include <bsd.port.mk>
