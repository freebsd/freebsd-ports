# New ports collection makefile for: handbrake
# Date created:		19 November 2004
# Whom:				Andrew Thompson <andy@fud.org.nz>
#
# $FreeBSD$
#

PORTNAME=		handbrake
PORTVERSION=	0.9.3
CATEGORIES=		multimedia
MASTER_SITES=			LOCAL/beech/handbrake/:main \
				LOCAL/beech/handbrake/:contrib
DISTFILES=		HandBrake-${PORTVERSION}.tar.gz:main \
				a52dec-0.7.4.tar.gz:contrib \
				faad2-2.6.1.tar.gz:contrib \
				ffmpeg-r15462.tar.gz:contrib \
				libdca-r81-strapped.tar.gz:contrib \
				libdvdread-0.9.7.tar.gz:contrib \
				faac-1.26.tar.gz:contrib \
				lame-3.98.tar.gz:contrib \
				libmp4v2-r45.tar.gz:contrib \
				libmkv-0.6.3.tar.gz:contrib \
				mpeg2dec-0.5.1.tar.gz:contrib \
				libogg-1.1.3.tar.gz:contrib \
				libsamplerate-0.1.4.tar.gz:contrib \
				libvorbis-aotuv_b5.tar.gz:contrib \
				libtheora-1.0.tar.gz:contrib \
				x264-r1028-83baa7f.tar.gz:contrib \
				xvidcore-1.1.3.tar.gz:contrib
DIST_SUBDIR=	handbrake

MAINTAINER=		ports@FreeBSD.org
COMMENT=	A DVD to MPEG-4 ripper and encoder

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam \
		pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_GMAKE=	yes

USE_AUTOTOOLS=	libtool:22 aclocal:110

LIBTOOLFILES=	${WRKSRC}/configure

WRKSRC=		${WRKDIR}/HandBrake-0.9.3
PLIST_FILES=	bin/handbrake

ONLY_FOR_ARCHS=	i386

JAM?=		${LOCALBASE}/bin/jam
APPLY?=		/usr/bin/apply

.include <bsd.port.pre.mk>

# nasm/yasm needed by x264
.if ${ARCH}=="i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.else
BUILD_DEPENDS+=	yasm>=0.6.0:${PORTSDIR}/devel/yasm
.endif

CONFIGURE_ENV+=	PKG_CONFIG_PATH=${WRKSRC}/contrib/lib/pkgconfig
MAKE_ENV+=	ARCH=${ARCH} MAKE=${GMAKE}

run-autotools-aclocal:

post-extract:
	@${APPLY} "${MV} %1 ${WRKSRC}/contrib/" \
		${WRKDIR}/a52dec \
		${WRKDIR}/faad2 \
		${WRKDIR}/ffmpeg \
		${WRKDIR}/libdca \
		${WRKDIR}/libdvdread \
		${WRKDIR}/faac \
		${WRKDIR}/lame \
		${WRKDIR}/libmp4v2 \
		${WRKDIR}/libmkv \
		${WRKDIR}/mpeg2dec \
		${WRKDIR}/libogg \
		${WRKDIR}/libsamplerate \
		${WRKDIR}/libvorbis \
		${WRKDIR}/libtheora \
		${WRKDIR}/x264 \
		${WRKDIR}/xvidcore

post-patch:
	@${REINPLACE_CMD} -e 's|machine/soundcard.h|sys/soundcard.h|g' \
		${WRKSRC}/contrib/a52dec/libao/audio_out_oss.c
# Remove the ports extraction code as it has already been done in post-extract:
# Fix a hardcoded "make" so gmake is used properly
# Remove a hardcoded "bash"
	@${REINPLACE_CMD} -E \
		-e 's|rm -rf [a-z0-9.-]* &&||g' \
		-e 's|\(gzip.*-) &&||g' \
		-e 's|\(gzip.*- ) &&||g' \
		-e 's| make | $$(MAKE) |g' \
		-e 's|bash ||g' \
		${WRKSRC}/contrib/Jamfile
# Following multimedia/x264 replace X86 with i386 and X86_64 with amd64
# This appears to be an issue only when building within the ports system
	@${REINPLACE_CMD} -E \
		-e 's|,X86)|,i386)|g'  \
		-e 's|,X86_64)|,amd64)|g' \
		${WRKSRC}/contrib/x264/Makefile
# The following patch fixes CPU count detection
	@${REINPLACE_CMD} -E \
		-e 's|/usr/sbin/sysctl|/sbin/sysctl|g'	\
		${WRKSRC}/libhb/ports.c
# Set release version so we don't depend on subversion
	@${REINPLACE_CMD} -E \
		-e 's|`svnversion`|0.9.3_freebsd-ports|g'  \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -E \
		-e 's|\$$\(HB_VERSION\)|0.9.3_freebsd-ports|g'	\
		${WRKSRC}/Makefile

do-build:
	@(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${JAM} -q)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/HandBrakeCLI ${PREFIX}/bin/handbrake

.include <bsd.port.post.mk>
