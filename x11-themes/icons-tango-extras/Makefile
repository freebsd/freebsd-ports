# $FreeBSD$

PORTNAME=	icons-tango-extras
PORTVERSION=	0.1.0
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	http://tango.freedesktop.org/releases/ \
		GENTOO
DISTNAME=	tango-icon-theme-extras-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extra set of icons from the Tango project

BUILD_DEPENDS=	${LOCALBASE}/libexec/icon-name-mapping:x11-themes/icon-naming-utils \
		${LOCALBASE}/share/icons/Tango/16x16/actions/add.png:x11-themes/icons-tango \
		Magick-config:graphics/ImageMagick
RUN_DEPENDS=	${LOCALBASE}/share/icons/Tango/16x16/actions/add.png:x11-themes/icons-tango

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GNOME=	intlhack
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
