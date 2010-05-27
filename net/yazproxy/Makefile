# New ports collection makefile for:	yazproxy
# Date created:				3 May 2004
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yazproxy
PORTVERSION=	1.3.5
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yazproxy/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A powerful general purpose Z39.50/SRW/SRU proxy

LIB_DEPENDS=	yazpp:${PORTSDIR}/net/yaz++

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared --with-yazpp=${LOCALBASE}/bin
USE_LDCONFIG=	yes

MAN8=		yazproxy.8

.include <bsd.port.mk>
