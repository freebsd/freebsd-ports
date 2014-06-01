# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mjpegtools
PORTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME:S/tools//}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Set of tools to record/playback/edit videos in MPEG format

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	v4l_compat>0:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg

CONFLICTS=	mplex-[0-9]*

USES=		gmake libtool pathfix pkgconfig
PATHFIX_MAKEFILEIN=	Makefile.am
USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
LIBTOOLIZE_ARGS=-i -c -f
ACLOCAL_ARGS=	--automake-acdir=${ACLOCAL_DIR} \
		-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing --foreign
CONFIGURE_ARGS=	--without-dga --without-x
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		mjpeg-howto

OPTIONS_DEFINE=		DOCS DV GTK2 PNG QUICKTIME SDL SIMD
OPTIONS_DEFAULT=	GTK2 PNG SDL
OPTIONS_SUB=		yes

DV_LIB_DEPENDS=		libdv.so:${PORTSDIR}/multimedia/libdv
DV_CONFIGURE_WITH=	libdv
GTK2_USE=		GNOME=gtk20
GTK2_CONFIGURE_WITH=	gtk
PNG_LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png
PNG_CONFIGURE_WITH=	libpng
QUICKTIME_LIB_DEPENDS=	libquicktime.so:${PORTSDIR}/multimedia/libquicktime
QUICKTIME_CONFIGURE_WITH=	libquicktime
SDL_USE=		SDL=gfx,sdl
SDL_CONFIGURE_OFF=	--without-libsdl --without-sdlgfx
SIMD_CONFIGURE_ENABLE=	simd-accel

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
CFLAGS:=	${CFLAGS:N-O*:N-fno-strict*}
.endif

.if ${ARCH} == "powerpc" && ${OSVERSION} > 900000
BROKEN=		Does not build on powerpc-9
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's| \*-\*-linux\*)| *-*-*)| ; \
		 /ARCHFLAGS=/s|^|#|g' ${WRKSRC}/configure.ac

pre-configure:
	@${RM} -f ${WRKSRC}/missing

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS BUGS CHANGES ChangeLog HINTS NEWS PLANS README README.DV \
	README.avilib README.glav README.AltiVec README.lavpipe \
	README.transist TODO
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
