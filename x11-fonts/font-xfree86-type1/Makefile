# Created by: Pawel Worach
# $FreeBSD$

PORTNAME=	font-xfree86-type1
PORTVERSION=	1.0.4
PORTREVISION=	1
MASTER_SITES=	XORG/individual/font
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org XFree86 Type1 font

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

USES=		fonts
FONTNAME=	Type1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fontrootdir=${PREFIX}/lib/X11/fonts
PLIST_FILES=	${FONTSDIR}/cursor.pfa

.include <bsd.port.mk>
