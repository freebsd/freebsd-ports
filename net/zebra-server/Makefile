# New ports collection makefile for:	zebra-server
# Date created:		14 Nov 2000
# Whom:			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zebra-server
PORTVERSION=	1.0.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/
DISTNAME=	zebra-${PORTVERSION:S/0./0pl/}

MAINTAINER=	demon@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/yaz-config:${PORTSDIR}/net/yaz
RUN_DEPENDS=	${LOCALBASE}/bin/yaz-config:${PORTSDIR}/net/yaz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-yazconfig=${LOCALBASE}/bin

.include <bsd.port.mk>
