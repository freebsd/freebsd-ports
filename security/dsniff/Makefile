# New ports collection makefile for:	dsniff
# Version required:	1.2
# Date created:		08 Jan 2000
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$

DISTNAME=	dsniff-1.2
CATEGORIES=	security
MASTER_SITES=	http://www.monkey.org/~dugsong/dsniff/

MAINTAINER=	kris@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet \
		${LOCALBASE}/lib/libnids.a:${PORTSDIR}/net/libnids

GNU_CONFIGURE=	yes
USE_XLIB=	yes

.include <bsd.port.mk>
