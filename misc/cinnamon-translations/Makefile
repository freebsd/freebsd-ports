# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/misc/cinnamon-translations/Makefile 19857 2014-09-13 09:46:37Z gusi $

PORTNAME=	cinnamon-translations
PORTVERSION=	2.4.2
CATEGORIES=	misc x11 gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Translations for the cinnamon desktop

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

USES=		gettext-tools
INSTALL_TARGET=	all
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|usr/share|${STAGEDIR}${PREFIX}/share|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
