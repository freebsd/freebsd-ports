PORTNAME=	icons-tango-extras
PORTVERSION=	0.1.0
PORTREVISION=	7
CATEGORIES=	x11-themes
MASTER_SITES=	https://tango.freedesktop.org/releases/
DISTNAME=	tango-icon-theme-extras-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extra set of icons from the Tango project
WWW=		http://tango-project.org/

LICENSE=	CC-BY-SA-2.5
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libexec/icon-name-mapping:x11-themes/icon-naming-utils \
		${LOCALBASE}/share/icons/Tango/16x16/actions/add.png:x11-themes/icons-tango
RUN_DEPENDS=	${LOCALBASE}/share/icons/Tango/16x16/actions/add.png:x11-themes/icons-tango

USES=		gmake gnome magick:build pkgconfig
USE_GNOME=	intlhack

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
