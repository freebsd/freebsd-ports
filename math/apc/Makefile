# New ports collection makefile for:	apc
# Date created:		May 1 1997
# Whom:			Eric A. Griff <eagriff@global2000.net>
#
# $FreeBSD$
#

PORTNAME=	apc
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An xforms based Auto Payment Calculator

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms

USE_XORG=	x11 xpm
MAN1=		apc.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/apc

.include <bsd.port.mk>
