# New ports collection makefile for:	yaz++
# Date created:				8 Nov 2002
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yaz++
PORTVERSION=	0.6
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz++/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A C++ programmer's toolkit for the development of Z39.50v3 clients and servers

LIB_DEPENDS=	yaz.2:${PORTSDIR}/net/yaz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared --with-yazconfig=${LOCALBASE}/bin
INSTALLS_SHLIB=	yes

MAN8=		yaz-proxy.8

.include <bsd.port.mk>
