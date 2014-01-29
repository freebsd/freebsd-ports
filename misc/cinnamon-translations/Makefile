# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/misc/cinnamon-translations/Makefile 18985 2014-01-21 12:30:41Z gusi $

PORTNAME=	cinnamon-translations
PORTVERSION=	2.0.3
CATEGORIES=	misc x11 gnome
MASTER_SITES=	http://github.com/linuxmint/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Translations for the cinnamon desktop

#USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
#USE_GNOME=	gnomeprefix gtk20 intltool introspection:build \
#		pygobject3 pygtk2  
USE_PYTHON=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
CONFIGURE_ARGS=	--disable-docbook-docs
CPPFLAGS+=	-I${LOCALBASE}/include -Wformat-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib

do-install:
	@(cd ${WRKSRC}/mo-export/ && ${CP} -pPR * ${STAGEDIR}${PREFIX}/share/locale)

.include <bsd.port.mk>
