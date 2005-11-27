# New ports collection makefile for:	dclock
# Date created:		15 Aug 1996
# Whom:			David Leonard <leonard@dstc.edu.au>
#
# $FreeBSD$
#

PORTNAME=	dclock
PORTVERSION=	pl6
CATEGORIES=	x11-clocks
MASTER_SITES=	# disappeared
DISTNAME=	Dclock

PATCH_SITES=	${MASTER_SITE_XCONTRIB}
PATCH_SITE_SUBDIR=	R6contrib-fixes
PATCHFILES=	Dclock-pl6.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 7-segment digital clock with optional military time and alarm

DEPRECATED=	mastersites disappeared
EXPIRATION_DATE=	2006-01-26

IGNOREFILES=	${DISTFILES}
USE_IMAKE=	yes
MAN1=		dclock.1
PLIST_FILES=	bin/dclock

.include <bsd.port.mk>
