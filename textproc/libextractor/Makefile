# New ports collection makefile for:	libextractor
# Date created:		25 May 2005
# Whom:			kevlo@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libextractor
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Library for keyword extraction

USE_GNOME=	glib20 gtk20
USE_PYTHON=	yes
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/libextractor
CONFIGURE_ARGS=	--disable-ltdl-install
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_JOBS_UNSAFE=	yes

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude libltdl

MAN1=	extract.1
MAN3=	libextractor.3

OPTIONS=	EXIV2 "Hook in Exiv2 dependency" on \
		FLAC "Hook in FLAC dependency" on \
		MPEG2 "Hook in MPEG2 dependency" on \
		VORBISFILE "Hook in VORBISFILE dependency" on \
		GSF "Hook in GSF (OLE2 (MS office) support) dependency" on \
		POPPLER "Hook in POPPLER (PDF support) dependency" on \
		RPM "Hook in RPM dependency" on \
		QT "Hook in QT dependency" on \
		FFMPEG "Hook in FFMPEG dependency" on

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/src/plugins/Makefile.*
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

check: build install
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

#regression-test: check

.include <bsd.port.pre.mk>

# libextractor's configure logic is: if exiv2 is present it will add support
# for it, if not present then it will not add support for it, but it cannot
# be disabled if present
.if !defined(WITHOUT_EXIV2) || exists(${LOCALBASE}/include/exiv2/exif.hpp)
LIB_DEPENDS+=	exiv2:${PORTSDIR}/graphics/exiv2
PLIST_SUB+=	EXIV2=""
.else
PLIST_SUB+=	EXIV2="@comment "
.endif

.if !defined(WITHOUT_FLAC) || exists(${LOCALBASE}/include/FLAC/all.h)
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.else
PLIST_SUB+=	FLAC="@comment "
.endif

.if !defined(WITHOUT_MPEG2) || exists(${LOCALBASE}/include/mpeg2dec/mpeg2.h)
LIB_DEPENDS+=	mpeg2:${PORTSDIR}/multimedia/libmpeg2
PLIST_SUB+=	MPEG2=""
.else
PLIST_SUB+=	MPEG2="@comment "
.endif

.if !defined(WITHOUT_VORBISFILE) || exists(${LOCALBASE}/include/vorbis/vorbisfile.h)
LIB_DEPENDS+=	vorbisfile:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBISFILE=""
.else
PLIST_SUB+=	VORBISFILE="@comment "
.endif

.if !defined(WITHOUT_GSF) || exists(${LOCALBASE}/include/libgsf-1/gsf/gsf.h)
LIB_DEPENDS+=	gsf-1:${PORTSDIR}/devel/libgsf
PLIST_SUB+=	GSF=""
.else
PLIST_SUB+=	GSF="@comment "
.endif

.if !defined(WITHOUT_POPPLER) || exists(${LOCALBASE}/include/poppler/goo/gmem.h)
LIB_DEPENDS+=	poppler:${PORTSDIR}/graphics/poppler
PLIST_SUB+=	POPPLER=""
.else
PLIST_SUB+=	POPPLER="@comment "
.endif

.if !defined(WITHOUT_RPM) || exists(${LOCALBASE}/include/rpm/rpmlib.h)
LIB_DEPENDS+=	rpm.1:${PORTSDIR}/archivers/rpm4
PLIST_SUB+=	RPM=""
.else
PLIST_SUB+=	RPM="@comment "
.endif

# QT can be disabled
.if !defined(WITHOUT_QT)
LIB_DEPENDS+=	QtGui:${PORTSDIR}/x11-toolkits/qt4-gui
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib -L${LOCALBASE}/lib/qt4"
CONFIGURE_ARGS+=--with-qt=${LOCALBASE}
PLIST_SUB+=	QT=""
.else
CONFIGURE_ARGS+=--with-qt=no
PLIST_SUB+=	QT="@comment "
.endif

# FFMPEG can be disabled
.if !defined(WITHOUT_FFMPEG)
LIB_DEPENDS+=	avformat:${PORTSDIR}/multimedia/ffmpeg
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
LIB_DEPENDS+=	swscale:${PORTSDIR}/multimedia/ffmpeg
LIB_DEPENDS+=	avutil:${PORTSDIR}/multimedia/ffmpeg
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
