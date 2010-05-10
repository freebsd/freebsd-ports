# ex:ts=8
# Ports collection makefile for:	gai
# Date created:			Feb 16, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gai
PORTVERSION=	0.5.10
PORTREVISION=	11
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	SF/${PORTNAME}/GAI%20-%20Library/${PORTNAME}-${PORTVERSION}

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	General Applet Interface Library

LIB_DEPENDS=	gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext

USE_BZIP2=	yes
USE_GL=		gl
USE_SDL=	sdl
USE_GNOME=	gnomepanel libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDLCONF=${SDL_CONFIG} \
		CPPFLAGS="`pkg-config --cflags libgnomeui-2.0`"

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
	${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif
.for dir in docking examples templates
	cd ${WRKSRC} && \
	${FIND} ${dir} -type d -exec ${MKDIR} "${EXAMPLESDIR}/{}" \; && \
	${FIND} ${dir} -type f -exec ${INSTALL_DATA} "{}" "${EXAMPLESDIR}/{}" \;
.endfor
	@${FIND} ${EXAMPLESDIR} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.mk>
