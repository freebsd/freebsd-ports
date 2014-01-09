# Created by: Eric A. Griff <eagriff@global2000.net>
# $FreeBSD$

PORTNAME=	apc
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An xforms based Auto Payment Calculator

LIB_DEPENDS=	libforms.so:${PORTSDIR}/x11-toolkits/xforms

USE_XORG=	x11 xpm
MAN1=		apc.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/apc

NO_STAGE=	yes
.include <bsd.port.mk>
