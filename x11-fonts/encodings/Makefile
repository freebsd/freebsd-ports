# $FreeBSD$

PORTNAME=	encodings
PORTVERSION=	1.0.5
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	XORG/individual/font

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org Encoding fonts

LICENSE=	PD

BUILD_DEPENDS=	mkfontscale:x11-fonts/mkfontscale

USES=		tar:bzip2 xorg
USE_XORG=	fontutil
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fontrootdir=${PREFIX}/share/fonts

post-install:
	cd ${STAGEDIR}${PREFIX}/share/fonts/encodings && mkfontscale -b -s -l -n -r -p ${PREFIX}/share/fonts/encodings -e . -e large .

.include <bsd.port.mk>
