# Ports collection makefile for:  vomit
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vomit
PORTVERSION=	0.2
CATEGORIES=	net security
MASTER_SITES=	http://vomit.xtdnet.nl/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent \
		${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/vomit-lite

MAN1=		vomit.1

.include <bsd.port.mk>
