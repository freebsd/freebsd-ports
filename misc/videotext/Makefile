# New ports collection makefile for:	videotext
# Date created:		Tue June 8 15:11:00 BST 1999
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	videotext
PORTVERSION=	0.6.19991029
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://elektra.e-technik.uni-ulm.de/~mbuck/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11/Xview TV Videotext/Teletext page viewer (.vtx files)

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		gawk:${PORTSDIR}/lang/gawk \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		xview.3:${PORTSDIR}/x11-toolkits/xview

USE_GMAKE=	yes
MAN1=		tunerctl.1 videotext.1 vtxget.1

FONTSDIR=	lib/X11/fonts/local
PLIST_SUB=	FONTSDIR=${FONTSDIR}

.include <bsd.port.mk>
