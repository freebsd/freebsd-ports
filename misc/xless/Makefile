# New ports collection makefile for:	xless
# Date created:		23 December 1996
# Whom:			Conrad Sabatier <conrads@home.com>
#
# $FreeBSD$
#

PORTNAME=	xless
PORTVERSION=	1.7
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_XCONTRIB} \
		ftp://ftp.cs.berkeley.edu/ucb/people/dglo/xless/
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 viewer for text files.  Useful as an add-on tool for other apps

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
MAN1=		xless.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
