# New ports collection makefile for:	transfig
# Date created:		9 August 1996
# Whom:			chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	transfig
PORTVERSION=	3.2.3c
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_XCONTRIB} \
		ftp://www-epb.lbl.gov/xfig/
MASTER_SITE_SUBDIR=	applications/drawing_tools/transfig
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	chuckr@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	ppmtogif:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		fig2dev.1 fig2ps2tex.1 pic2tpic.1 transfig.1

.include <bsd.port.mk>
