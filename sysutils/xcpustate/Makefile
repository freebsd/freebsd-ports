# ex:ts=8
# Ports collection makefile for:  xcpustate
# Date created:			  31-Dec-1995
# Whom:				  David O'Brien <obrien@cs.ucdavis.edu>
#
# $FreeBSD$
#

PORTNAME=	xcpustate
PORTVERSION=	2.5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/jdd/xcpustate/  \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities
EXTRACT_SUFX=	.shar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System monitoring utility graphicaly showing cpu load and status

EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
USE_IMAKE=	yes
NO_WRKSUBDIR=	yes

MAN1=		xcpustate.1

.include <bsd.port.pre.mk>

.if ${ARCH} == sparc64
BROKEN=		Does not compile
.endif

.include <bsd.port.post.mk>
