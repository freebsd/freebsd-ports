# ex:ts=8
# Ports collection makefile for:	gai
# Date created:			Feb 16, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gai
PORTVERSION=	0.5.4
PORTREVISION=	0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General Applet Interface Library

LIB_DEPENDS=	gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext

USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_GL=		yes
USE_SDL=	sdl
USE_GNOME=	gnomehack gnomeprefix gdkpixbuf gtk20 pango gnomepanel
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDLCONF=${SDL_CONFIG}

PLIST_FILES=	include/gai/gai.h lib/libgai.so.0.5.4 lib/libgai.so.0 \
		lib/libgai.so libdata/pkgconfig/gai.pc
PLIST_DIRS=	include/gai
INSTALLS_SHLIB=	yes

.if ${MACHINE_ARCH:L} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|sdl-config --|${SDL_CONFIG} --|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|lib/pkgconfig|libdata/pkgconfig|g" \
		-e "s|-O2|${CFLAGS}|g" ${WRKSRC}/gai/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
	@${FIND} ${DOCSDIR} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${DOCSDIR} -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}
	@${MKDIR} ${EXAMPLESDIR}
.for dir in docking examples templates
	${CP} -R ${WRKSRC}/${dir} ${EXAMPLESDIR}
.endfor
	@${FIND} ${EXAMPLESDIR} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
