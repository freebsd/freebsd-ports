# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mjpegtools
PORTVERSION=	2.1.0
PORTREVISION=	9
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME:S/tools//}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Set of tools to record/playback/edit videos in MPEG format

LICENSE=	GPLv2+

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat

CONFLICTS=	mplex-[0-9]*

USES=		gmake jpeg libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-dga --without-x
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

INFO=		mjpeg-howto

OPTIONS_DEFINE=		DOCS DV GTK2 PNG QUICKTIME SDL
OPTIONS_DEFAULT=	GTK2 PNG SDL
OPTIONS_SUB=		yes

DV_LIB_DEPENDS=		libdv.so:multimedia/libdv
DV_CONFIGURE_WITH=	libdv
GTK2_USE=		GNOME=gtk20
GTK2_CONFIGURE_WITH=	gtk
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	libpng
QUICKTIME_LIB_DEPENDS=	libquicktime.so:multimedia/libquicktime
QUICKTIME_CONFIGURE_WITH=	libquicktime
SDL_USE=		SDL=gfx,sdl
SDL_CONFIGURE_OFF=	--without-libsdl --without-sdlgfx

.include <bsd.port.options.mk>

.if ${ARCH} == i386 || ${ARCH} == powerpc
USES+=		compiler:c++11-lang
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's| \*-\*-linux\*)| *-*-*)|' \
		-e '/ARCHFLAGS=/d' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS BUGS CHANGES ChangeLog HINTS NEWS PLANS README README.DV \
	README.avilib README.glav README.AltiVec README.lavpipe \
	README.transist TODO
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
