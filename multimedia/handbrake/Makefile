# New ports collection makefile for: handbrake
# Date created:        19 November 2004
# Whom:                Andrew Thompson <andy@fud.org.nz>
#
# $FreeBSD$
#

PORTNAME=	handbrake
PORTVERSION=	0.9.2
CATEGORIES=	multimedia
MASTER_SITES=	http://download.handbrake.fr/handbrake/releases/:main \
		http://download.m0k.org/handbrake/releases/:main \
		http://download.handbrake.fr/handbrake/contrib/:contrib \
		http://download.m0k.org/handbrake/contrib/:contrib
DISTFILES=	HandBrake-${PORTVERSION}.tar.gz:main \
		faac-1.24.tar.gz:contrib \
		lame-3.96.1.tar.gz:contrib \
		libdca-r81-strapped.tar.gz:contrib \
		libdvdcss-1.2.9.tar.gz:contrib \
		libdvdread-0.9.7.tar.gz:contrib \
		libmkv-0.6.1.3.tar.gz:contrib \
		libogg-1.1.2.tar.gz:contrib \
		libvorbis-aotuv_b5.tar.gz:contrib \
		mpeg2dec-0.4.1.tar.gz:contrib \
		mpeg4ip-1.3.tar.gz:contrib \
		xvidcore-1.1.2.tar.gz:contrib \
		ffmpeg-9816.tar.gz:contrib \
		x264-r736.tar.gz:contrib \
		a52dec-0.7.4.tar.gz:contrib \
		libsamplerate-0.1.2.tar.gz:contrib
DIST_SUBDIR=	handbrake

MAINTAINER=	jonathan@kc8onw.net
COMMENT=	A DVD to MPEG-4 ripper and encoder

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam \
		pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

NO_CDROM=	CSS code may violate the DMCA

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15
LIBTOOLFILES=	${WRKSRC}/contrib/a52dec/configure \
		${WRKSRC}/contrib/libdvdcss/configure \
		${WRKSRC}/contrib/libdvdread/configure \
		${WRKSRC}/contrib/faac/configure \
		${WRKSRC}/contrib/lame/configure \
		${WRKSRC}/contrib/mpeg4ip/configure \
		${WRKSRC}/contrib/mpeg2dec/configure \
		${WRKSRC}/contrib/libogg/configure \
		${WRKSRC}/contrib/libsamplerate/configure \
		${WRKSRC}/contrib/libvorbis/configure

WRKSRC=		${WRKDIR}/HandBrake
PLIST_FILES=	bin/handbrake

JAM?=		${LOCALBASE}/bin/jam
APPLY?=		/usr/bin/apply

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		Needs testing
.endif

# nasm/yasm needed by x264
.if ${ARCH}=="i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.else
BUILD_DEPENDS+=	yasm>=0.6.0:${PORTSDIR}/devel/yasm
.endif

CONFIGURE_ENV+=	PKG_CONFIG_PATH=${WRKSRC}/contrib/lib/pkgconfig
MAKE_ENV+=	ARCH=${ARCH} MAKE=${GMAKE}

post-extract:
	@${APPLY} "${MV} %1 ${WRKSRC}/contrib/" \
		${WRKDIR}/a52dec \
		${WRKDIR}/faac \
		${WRKDIR}/ffmpeg \
		${WRKDIR}/lame \
		${WRKDIR}/libdca \
		${WRKDIR}/libdvdcss \
		${WRKDIR}/libdvdread \
		${WRKDIR}/libmkv \
		${WRKDIR}/libogg \
		${WRKDIR}/libsamplerate \
		${WRKDIR}/libvorbis \
		${WRKDIR}/mpeg2dec \
		${WRKDIR}/mpeg4ip \
		${WRKDIR}/x264 \
		${WRKDIR}/xvidcore

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g ; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g ; \
		s|%%CONTRIB%%|${WRKSRC}/contrib|g ; \
		s|./bootstrap|${SETENV} CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" ${CONFIGURE_ENV} ./bootstrap|g ; \
		s|./configure|${SETENV} CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" ${CONFIGURE_ENV} ./configure|g' \
			${WRKSRC}/contrib/Jamfile
	@${REINPLACE_CMD} -e 's|-O3||g ; s|-O20||g ; s|-O4 -ffast-math||g ; \
		s| -mtune=.*"|"|g ; s| -mcpu=.*"|"|g ; \
		s|-fomit-frame-pointer||g ; s|-pthread|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g ; \
		s|=`echo \".*$$CFLAGS\".*sed.*`|=`echo \"$$OPT_CFLAGS $$CFLAGS\"`|g' \
			${WRKSRC}/contrib/*/configure
	@${REINPLACE_CMD} -e 's|>&/|>/|g' \
		${WRKSRC}/contrib/mpeg4ip/configure
	@${REINPLACE_CMD} -e 's|\\$$(PREFIX)|${WRKSRC}/contrib|g ; \
		s|$$(PREFIX)|${WRKSRC}/contrib|g ; \
		s|$$PREFIX|${WRKSRC}/contrib|g' \
			${WRKSRC}/contrib/ffmpeg/configure

# jam -dx, it will giving a verbose of build.
do-build:
	@(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${JAM} -dx)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/HandBrakeCLI ${PREFIX}/bin/handbrake

.include <bsd.port.post.mk>
