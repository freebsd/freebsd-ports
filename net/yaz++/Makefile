# New ports collection makefile for:	yaz++
# Date created:				8 Nov 2002
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yaz++
PORTVERSION=	0.9
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz++/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	C++ toolkit for development of Z39.50v3 clients and servers

LIB_DEPENDS=	yaz.2:${PORTSDIR}/net/yaz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared --with-yaz=${LOCALBASE}/bin
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
