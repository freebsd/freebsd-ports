# New ports collection makefile for:	icons-tango
# Date created:		2005-11-05
# Whom:			Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	icons-tango
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://tango-project.org/releases/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	tango-icon-theme-${PORTVERSION}

MAINTAINER=	pneumann@gmail.com
COMMENT=	A basic set of icons for the most common usage

BUILD_DEPENDS=	${LOCALBASE}/libexec/icon-name-mapping:${PORTSDIR}/x11-themes/icon-naming-utils \
		Magick-config:${PORTSDIR}/graphics/ImageMagick

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	intlhack

.include <bsd.port.mk>
