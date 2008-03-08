# New ports collection makefile for:	tv-fonts
# Date created:				19 June 2004
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	tv-fonts
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://dl.bytesex.org/releases/${PORTNAME}/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A number of fonts which are useful for TV applications

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale
RUN_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USE_GMAKE=	yes
USE_BZIP2=	yes

FONTSDIR=	${PREFIX}/lib/X11/fonts/misc
FONTS=		caption.pcf.gz captioni.pcf.gz led-iso10646-1.pcf.gz \
		led-iso8859-1.pcf.gz led-iso8859-10.pcf.gz led-iso8859-13.pcf.gz \
		led-iso8859-14.pcf.gz led-iso8859-15.pcf.gz led-iso8859-2.pcf.gz \
		led-iso8859-3.pcf.gz led-iso8859-4.pcf.gz led-iso8859-5.pcf.gz \
		led-iso8859-7.pcf.gz led-iso8859-8.pcf.gz led-iso8859-9.pcf.gz \
		led-koi8-r.pcf.gz teletext1.pcf.gz teletext1i.pcf.gz \
		teletext2.pcf.gz teletext2i.pcf.gz teletext4.pcf.gz \
		teletext4i.pcf.gz

do-install:
	@${MKDIR} ${FONTSDIR}
.for font in ${FONTS}
	${INSTALL_DATA} ${WRKSRC}/${font} ${FONTSDIR}
.endfor

post-install:
	@-${X11BASE}/bin/fc-cache -f -v ${FONTSDIR}

.include <bsd.port.mk>
