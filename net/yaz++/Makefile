# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yaz++
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yazpp/
DISTNAME=	yazpp-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	C++ toolkit for development of Z39.50v3 clients and servers

LIB_DEPENDS=	libyaz.so:${PORTSDIR}/net/yaz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared --with-yaz=${LOCALBASE}/bin
USE_LDCONFIG=	yes

MAN1=		yazpp-config.1

NO_STAGE=	yes
.include <bsd.port.mk>
