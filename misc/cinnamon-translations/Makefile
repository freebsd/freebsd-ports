# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/misc/cinnamon-translations/Makefile 19857 2014-09-13 09:46:37Z gusi $

PORTNAME=	cinnamon-translations
PORTVERSION=	2.2.4
CATEGORIES=	misc x11 gnome
MASTER_SITES=	http://github.com/linuxmint/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Translations for the cinnamon desktop

USES=		tar:xz
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	@(cd ${WRKSRC}/mo-export/ && ${CP} -pPR * ${STAGEDIR}${PREFIX}/share/locale)

.include <bsd.port.mk>
