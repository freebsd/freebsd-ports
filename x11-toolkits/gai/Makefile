# Created by: ijliao
# $FreeBSD$

PORTNAME=	gai
PORTVERSION=	0.5.10
PORTREVISION=	15
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	SF/${PORTNAME}/GAI%20-%20Library/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@freebsd.org
COMMENT=	General Applet Interface Library

LIB_DEPENDS=	libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext

USES=		pkgconfig tar:bzip2
USE_GL=		gl
USE_SDL=	sdl
USE_GNOME=	libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDLCONF=${SDL_CONFIG}
CONFIGURE_ARGS=	--disable-gnome
CPPFLAGS+=	`pkg-config --cflags libgnomeui-2.0`

PLIST_FILES=	include/gai/gai.h lib/libgai.so.${PORTVERSION} \
		lib/libgai.so.0 lib/libgai.so libdata/pkgconfig/gai.pc \
		share/locale/de/LC_MESSAGES/gai.mo
PLIST_DIRS=	include/gai
PORTDOCS=	*
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|sdl-config --|${SDL_CONFIG} --|g; \
		s|/usr/X11R6|${LOCALBASE}|g" ${WRKSRC}/configure

post-install:
	cd ${WRKSRC}/docs && \
	${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${DOCSDIR}/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${DOCSDIR}/{}" \;
.for dir in docking examples templates
	cd ${WRKSRC} && \
	${FIND} ${dir} -type d -exec ${MKDIR} "${STAGEDIR}${EXAMPLESDIR}/{}" \; && \
	${FIND} ${dir} -type f -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${EXAMPLESDIR}/{}" \;
.endfor
	@${FIND} ${STAGEDIR}${EXAMPLESDIR} -type f | \
		${SED} "s,^${STAGEDIR}${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} "s,^${STAGEDIR}${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.mk>
