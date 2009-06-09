# New ports collection makefile for:    jmk-x11-fonts
# Date created:         Sat Aug 19 20:36:34 CEST 2000
# Whom:                 olgeni@uli.it
#
# $FreeBSD$
#

PORTNAME=	jmk-x11-fonts
PORTVERSION=	3.0
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.jmknoble.net/fonts/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Jim Knoble's font package for X

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USE_IMAKE=	yes

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/jmk
	@${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${PREFIX}/lib/X11/fonts/jmk
	@${INSTALL_DATA} ${WRKSRC}/fonts.dir ${PREFIX}/lib/X11/fonts/jmk

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
