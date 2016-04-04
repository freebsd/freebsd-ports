# Created by: ijliao
# $FreeBSD$

PORTNAME=	gai
PORTVERSION=	0.5.10
PORTREVISION=	16
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	SF/${PORTNAME}/GAI%20-%20Library/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General Applet Interface Library

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext

USES=		gettext-tools pkgconfig tar:bzip2
USE_GL=		gl
USE_SDL=	sdl
USE_GNOME=	libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDLCONF=${SDL_CONFIG}
CONFIGURE_ARGS=	--disable-gnome
CPPFLAGS+=	`pkg-config --cflags libgnomeui-2.0`

PORTDOCS=	*
PORTEXAMPLES=	*
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e "s|sdl-config --|${SDL_CONFIG} --|g; \
		s|/usr/X11R6|${LOCALBASE}|g" ${WRKSRC}/configure

post-install-DOCS-on:
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "docking examples templates" ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
