# Created by: Phillip Neumann <pneumann@gmail.com>
# $FreeBSD$

PORTNAME=	icons-tango
PORTVERSION=	0.8.90
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	tango-icon-theme-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Basic set of icons for the most common usage

BUILD_DEPENDS=	${LOCALBASE}/libexec/icon-name-mapping:${PORTSDIR}/x11-themes/icon-naming-utils \
		Magick-config:${PORTSDIR}/graphics/ImageMagick

GNU_CONFIGURE=	yes
USE_GNOME=	intlhack
USES+=		pathfix gmake pkgconfig
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
