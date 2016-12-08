# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yazproxy
PORTVERSION=	1.3.9
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yazproxy/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Powerful general purpose Z39.50/SRW/SRU proxy

LIB_DEPENDS=	libyazpp.so:net/yaz++

USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared --with-yazpp=${LOCALBASE}/bin
USE_LDCONFIG=	yes

.include <bsd.port.mk>
