# New ports collection makefile for:	transfig
# Date created:		9 August 1996
# Whom:			chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	transfig
PORTVERSION=	3.2.4
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.xfig.org/xfigdist/ \
		ftp://www-epb.lbl.gov/xfig/%SUBDIR%/
MASTER_SITE_SUBDIR=	. previous_versions
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools to convert Xfig's .fig files

USE_GHOSTSCRIPT_RUN=	yes

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	ppmtogif:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		fig2dev.1 fig2ps2tex.1 pic2tpic.1 transfig.1

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
