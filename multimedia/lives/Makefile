# New ports collection makefile for:	lives
# Date created:		3 November 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lives
PORTVERSION=	1.0.9
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.xs4all.nl/~salsaman/lives/current/
DISTNAME=	LiVES-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video editing system

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		oil-0.3.0:${PORTSDIR}/devel/liboil \
		visual-0.4.0:${PORTSDIR}/graphics/libvisual04 \
		dv.4:${PORTSDIR}/multimedia/libdv \
		theora.0:${PORTSDIR}/multimedia/libtheora \
		mjpegutils-1.9.0:${PORTSDIR}/multimedia/mjpegtools
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		sox:${PORTSDIR}/audio/sox \
		ogg123:${PORTSDIR}/audio/vorbis-tools \
		convert:${PORTSDIR}/graphics/ImageMagick \
		sswf:${PORTSDIR}/graphics/sswf \
		ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		mkvmerge:${PORTSDIR}/multimedia/mkvtoolnix \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		ogmmerge:${PORTSDIR}/multimedia/ogmtools \
		transcode:${PORTSDIR}/multimedia/transcode \
		x264:${PORTSDIR}/multimedia/x264 \
		xmms:${PORTSDIR}/multimedia/xmms

OPTIONS=	FREI0R "Enable frei0r support" off

WRKSRC=		${WRKDIR}/${DISTNAME:L}

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_SDL=	sdl
USE_PYTHON=	yes
USE_PERL5=	yes
USE_CDRTOOLS=	yes
USE_GETTEXT=	yes
USE_GHOSTSCRIPT_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-ldvgrab

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS} -fPIC
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

DOC_FILES=	AUTHORS BUGS ChangeLog FEATURES GETTING.STARTED README \
		OMC/lives-OMC.txt \
		RFX/LiVES-Perl.odt RFX/rfxbuilder.odt RFX/RFX.spec \
		docs/clip_format.txt \
		lives-plugins/marcos-encoders/README.multi_encoder \
		weed-docs/weedspec.txt weed-docs/weedevents.txt

PORT_VERBS=	lives LiVES _encoder.py midistart midistop smogrify sendOSC

# Restrict to stable versions.
PORTSCOUT=	limit:^1\.0\.[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_FREI0R)
BUILD_DEPENDS+=	${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r
RUN_DEPENDS+=	${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r
PLIST_SUB+=	FREI0R=""
.else
CONFIGURE_ENV+=	ac_cv_header_frei0r_h=no
PLIST_SUB+=	FREI0R="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/LIBS/s|-ldl ||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|: install-docDATA|:|g ; \
		 /update_with_plugins.*install/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-d alsa|-d oss|' ${WRKSRC}/src/main.c
.for file in src/audio.c lives-plugins/plugins/decoders/dv_decoder.c
	@${REINPLACE_CMD} -e 's|off64_t|off_t|g ; \
		 s|lseek64|lseek|g' ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e 's|/usr/local/lib/|${LOCALBASE}/lib/|g' \
		${WRKSRC}/lives-plugins/weed-plugins/frei0r.c
	@${FIND} ${WRKSRC} -name "Makefile.in" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		'/FLAGS/s|-O3||g ; \
		 /FLAGS/s|-ldl||g ; \
		 /flags/s|-L/usr/lib64||g ; \
		 /flags/s|-Wl,-Bsymbolic||g ; \
		 /flags/s|--tag=disable-static||g'

pre-build:
	@cd ${WRKSRC}/po; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} update-po

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor 
.endif

.include <bsd.port.post.mk>
