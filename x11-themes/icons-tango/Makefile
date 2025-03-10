PORTNAME=	icons-tango
PORTVERSION=	0.8.90
PORTREVISION=	4
CATEGORIES=	x11-themes
MASTER_SITES=	https://tango.freedesktop.org/releases/
DISTNAME=	tango-icon-theme-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Basic set of icons for the most common usage
WWW=		http://tango.freedesktop.org/

LICENSE=	UNKNOWN
LICENSE_NAME=	UNKNOWN
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	${LOCALBASE}/libexec/icon-name-mapping:x11-themes/icon-naming-utils

USES=		gettext-tools gmake gnome magick:build pathfix pkgconfig
USE_GNOME=	intlhack

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
