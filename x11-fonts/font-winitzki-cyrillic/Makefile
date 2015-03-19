# Created by: Pawel Worach
# $FreeBSD$

PORTNAME=	font-winitzki-cyrillic
PORTVERSION=	1.0.3
PORTREVISION=	2
MASTER_SITES=	XORG/individual/font
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org Winitzki Cyrillic font

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

USES=		fonts
FONTNAME=	cyrillic
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fontrootdir=${PREFIX}/lib/X11/fonts
PLIST_FILES=	${FONTSDIR}/proof9x16.pcf.gz

.include <bsd.port.mk>
