# $FreeBSD$

PORTNAME=	icons-tango-extras
PORTVERSION=	0.1.0
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	http://tango.freedesktop.org/releases/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	tango-icon-theme-extras-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	A extra set of icons from the Tango project

BUILD_DEPENDS=	${LOCALBASE}/libexec/icon-name-mapping:${PORTSDIR}/x11-themes/icon-naming-utils \
		${LOCALBASE}/share/icons/Tango/16x16/actions/add.png:${PORTSDIR}/x11-themes/icons-tango \
		Magick-config:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS=	${LOCALBASE}/share/icons/Tango/16x16/actions/add.png:${PORTSDIR}/x11-themes/icons-tango

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	intlhack
INSTALLS_ICONS=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
