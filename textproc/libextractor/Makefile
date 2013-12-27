# Created by: kevlo@FreeBSD.org
# $FreeBSD$

PORTNAME=	libextractor
PORTVERSION=	0.6.2
PORTREVISION=	15
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Library for keyword extraction

USE_GNOME=	glib20 gtk20
USES=		pathfix pkgconfig
USE_PYTHON=	yes
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/libextractor
CONFIGURE_ARGS=	--disable-ltdl-install
CPPFLAGS+=	-I${LOCALBASE}/include/ffmpeg0 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/ffmpeg0 -L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

EXTRACT_AFTER_ARGS=	--exclude libltdl

MAN1=	extract.1
MAN3=	libextractor.3

OPTIONS_DEFINE=	EXIV2 FLAC MPEG2 VORBIS GSF POPPLER RPM QT FFMPEG
GSF_DESC=	GSF (OLE2 (MS office) support)
RPM_DESC=	RPM support
OPTIONS_DEFAULT=	EXIV2 FLAC MPEG2 VORBIS GSF POPPLER RPM QT FFMPEG

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f
	@${REINPLACE_CMD} \
		-e 's|-lpthread|${PTHREAD_LIBS}|g' \
		-e 's|-lavcodec|-lavcodec0|g' \
		-e 's|-lavformat|-lavformat0|g' \
		-e 's|-lswscale|-lswscale0|g' \
		-e 's|-lavutil|-lavutil0|g' \
		${WRKSRC}/src/plugins/Makefile.*
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g' \
		-e 's|-lstdc++||g' \
		${WRKSRC}/configure

check: build install
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

#regression-test: check

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
BROKEN=	does not package
.endif

# libextractor's configure logic is: if exiv2 is present it will add support
# for it, if not present then it will not add support for it, but it cannot
# be disabled if present

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXIV2}
LIB_DEPENDS+=	exiv2.12:${PORTSDIR}/graphics/exiv2
PLIST_SUB+=	EXIV2=""
.else
PLIST_SUB+=	EXIV2="@comment "
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.else
PLIST_SUB+=	FLAC="@comment "
.endif

.if ${PORT_OPTIONS:MMPEG2}
LIB_DEPENDS+=	mpeg2:${PORTSDIR}/multimedia/libmpeg2
PLIST_SUB+=	MPEG2=""
.else
PLIST_SUB+=	MPEG2="@comment "
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbisfile:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBIS=""
.else
PLIST_SUB+=	VORBIS="@comment "
.endif

.if ${PORT_OPTIONS:MGSF}
LIB_DEPENDS+=	gsf-1:${PORTSDIR}/devel/libgsf
PLIST_SUB+=	GSF=""
.else
PLIST_SUB+=	GSF="@comment "
.endif

.if ${PORT_OPTIONS:MPOPPLER}
LIB_DEPENDS+=	libpoppler.so:${PORTSDIR}/graphics/poppler
PLIST_SUB+=	POPPLER=""
.else
PLIST_SUB+=	POPPLER="@comment "
.endif

.if ${PORT_OPTIONS:MRPM}
LIB_DEPENDS+=	rpm:${PORTSDIR}/archivers/rpm4
PLIST_SUB+=	RPM=""
.else
PLIST_SUB+=	RPM="@comment "
.endif

# QT can be disabled
.if ${PORT_OPTIONS:MQT}
LIB_DEPENDS+=	QtGui:${PORTSDIR}/x11-toolkits/qt4-gui
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/qt4
CONFIGURE_ARGS+=--with-qt=${LOCALBASE}
PLIST_SUB+=	QT=""
.else
CONFIGURE_ARGS+=--with-qt=no
PLIST_SUB+=	QT="@comment "
.endif

# FFMPEG can be disabled
.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	libavformat0.so:${PORTSDIR}/multimedia/ffmpeg0
LIB_DEPENDS+=	libavcodec0.so:${PORTSDIR}/multimedia/ffmpeg0
LIB_DEPENDS+=	libswscale0.so:${PORTSDIR}/multimedia/ffmpeg0
LIB_DEPENDS+=	libavutil0.so:${PORTSDIR}/multimedia/ffmpeg0
CONFIGURE_ARGS+=--enable-ffmpeg
PLIST_SUB+=	FFMPEG=""
.else
CONFIGURE_ARGS+=--disable-ffmpeg
PLIST_SUB+=	FFMPEG="@comment "
.endif

patch-autotools-libtool::
	@(cd ${PATCH_WRKSRC}; \
	for f in ${LIBTOOLFILES}; do \
		${CP} $$f $$f.tmp; \
		${SED} -e "/^ltmain=/s^\$$ac_aux_dir/ltmain.sh^${LTMAIN}^g" \
			$$f.tmp > $$f; \
		${RM} $$f.tmp; \
	done);

.include <bsd.port.post.mk>
