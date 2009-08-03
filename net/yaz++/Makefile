# New ports collection makefile for:	yaz++
# Date created:				8 Nov 2002
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yaz++
PORTVERSION=	1.1.4
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yazpp/
DISTNAME=	yazpp-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	C++ toolkit for development of Z39.50v3 clients and servers

LIB_DEPENDS=	yaz.3:${PORTSDIR}/net/yaz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared --with-yaz=${LOCALBASE}/bin
USE_LDCONFIG=	yes

MAN8=		yazpp-config.8

.include <bsd.port.mk>
