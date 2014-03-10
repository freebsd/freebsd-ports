# Created by: ijliao
# $FreeBSD$

PORTNAME=	gai
PORTVERSION=	0.5.10
PORTREVISION=	14
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	SF/${PORTNAME}/GAI%20-%20Library/${PORTNAME}-${PORTVERSION}

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	General Applet Interface Library

LIB_DEPENDS=	libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext

USE_BZIP2=	yes
USES=		pkgconfig
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

post-patch:
	@${REINPLACE_CMD} -e "s|sdl-config --|${SDL_CONFIG} --|g; \
		s|/usr/X11R6|${LOCALBASE}|g" ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs && \
	${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${DOCSDIR}/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${DOCSDIR}/{}" \;
.endif
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
