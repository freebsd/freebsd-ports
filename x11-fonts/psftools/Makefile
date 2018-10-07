# $FreeBSD$

PORTNAME=	psftools
PORTVERSION=	1.0.10
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.seasip.info/Unix/PSF/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Converters for simple fixed-width bitmap fonts

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

PORTSCOUT=	ignore:1

.include <bsd.port.mk>
