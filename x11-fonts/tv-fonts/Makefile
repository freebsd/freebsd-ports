# New ports collection makefile for:	tv-fonts
# Date created:				19 June 2004
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	tv-fonts
PORTVERSION=	1.1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://dl.bytesex.org/releases/${PORTNAME}/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A number of fonts which are useful for TV applications

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}

USE_X_PREFIX=	yes
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

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xorg
PLIST_SUB+=	NEWMTREE=""
.else
PLIST_SUB+=	NEWMTREE="@comment "
.endif

.include <bsd.port.post.mk>
