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
MASTER_SITES=	http://ftp.cs.toronto.edu/pub/jdd/xcpustate/
EXTRACT_SUFX=	.shar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System monitoring utility graphically showing cpu load and status

EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=	# none
EXTRACT_AFTER_ARGS=	| ${SH}

NO_WRKSUBDIR=	yes

USE_XORG=	ice sm x11 xaw xext xmu xt
USE_IMAKE=	yes

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
