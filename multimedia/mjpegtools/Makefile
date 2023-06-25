PORTNAME=	mjpegtools
PORTVERSION=	2.1.0
PORTREVISION=	16
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME:S/tools//}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Set of tools to record/playback/edit videos in MPEG format
WWW=		http://mjpeg.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat

CONFLICTS=	mplex

USES=		compiler:c++11-lang gmake gnome jpeg libtool localbase pathfix \
		pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-dga --without-libquicktime --without-x
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}

INFO=		mjpeg-howto

OPTIONS_DEFINE=		DOCS DV GTK2 PNG SDL
OPTIONS_DEFAULT=	GTK2 PNG SDL
OPTIONS_SUB=		yes

DV_LIB_DEPENDS=		libdv.so:multimedia/libdv
DV_CONFIGURE_WITH=	libdv
GTK2_USE=		GNOME=gtk20
GTK2_CONFIGURE_WITH=	gtk
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	libpng
SDL_USES=		sdl
SDL_USE=		SDL=gfx,sdl
SDL_CONFIGURE_OFF=	--without-libsdl --without-sdlgfx

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CPPFLAGS+=  -Dregister=
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's| \*-\*-linux\*)| *-*-*)|' \
		-e '/ARCHFLAGS=/d' ${WRKSRC}/configure
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
	@${REINPLACE_CMD} -e 's|auto_ptr|unique_ptr|' \
		${WRKSRC}/mplex/main.cpp
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS BUGS CHANGES ChangeLog HINTS NEWS PLANS README README.DV \
	README.avilib README.glav README.AltiVec README.lavpipe \
	README.transist TODO
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
