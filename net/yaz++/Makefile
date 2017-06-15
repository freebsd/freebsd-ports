# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yaz++
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yazpp/
DISTNAME=	yazpp-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	C++ toolkit for development of Z39.50v3 clients and servers

LIB_DEPENDS=	libyaz.so:net/yaz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-yaz=${LOCALBASE}/bin
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	yes

.include <bsd.port.mk>
