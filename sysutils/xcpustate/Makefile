# ex:ts=8
# Ports collection makefile for:  xcpustate
# Date created:			  31-Dec-1995
# Whom:				  David O'Brien <obrien@cs.ucdavis.edu>
#
# $FreeBSD$
#

PORTNAME=	xcpustate
PORTVERSION=	2.9
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/jdd/xcpustate/  \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities
EXTRACT_SUFX=	.shar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System monitoring utility graphicaly showing cpu load and status

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xt
NO_WRKSUBDIR=	yes

MAN1=		xcpustate.1

.include <bsd.port.mk>
