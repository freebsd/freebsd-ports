# Created by: Pawel Worach
# $FreeBSD$

PORTNAME=	font-sun-misc
PORTVERSION=	1.0.3
PORTREVISION=	2
MASTER_SITES=	XORG/individual/font
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org miscellaneous Sun fonts

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

USES=		fonts tar:bzip2
FONTNAME=	misc
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fontrootdir=${PREFIX}/lib/X11/fonts

.include <bsd.port.mk>
