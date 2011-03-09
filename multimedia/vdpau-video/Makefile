# New ports collection makefile for:	vdpau-video
# Date created:				5 Jan 2011
# Whom:					Anonymous
#
# $FreeBSD$
#

PORTNAME=	vdpau-video
DISTVERSION=	0.7.3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.splitted-desktop.com/~gbeauchesne/${PORTNAME}/

MAINTAINER=	swell.k@gmail.com
COMMENT=	A VDPAU-based backend for VAAPI

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libva.pc:${PORTSDIR}/multimedia/libva \
		${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	vdpau.1:${PORTSDIR}/multimedia/libvdpau

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

USE_GMAKE=	yes
USE_GL=		gl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-isystem${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

VDPAU_PTHREAD_LIBS!=	${CC} -dumpspecs | ${GREP} -m 1 pthread: | ${SED} -e 's|^.*%{\!pg: %{pthread:|| ; s|}.*$$||' || ${TRUE}

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--disable-debug
.endif

.if defined(STRIP) && ${STRIP} != ""
INSTALL_TARGET=	install-strip
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LIBS/{ s/-ldl//; \
		s/-lrt//; s/-lpthread/${PTHREAD_LIBS}/; }' \
		-e 's|driverdir|& --define-variable prefix=${PREFIX}|' \
		-e '/\^vdpau_version/s|$$CC -E|& ${CPPFLAGS}|' \
		 ${WRKSRC}/configure
	${REINPLACE_CMD} 's/^vdpau.*LDFLAGS.*/& \
		-Wl,-lc ${VDPAU_PTHREAD_LIBS:S/^/-Wl,/}/' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
