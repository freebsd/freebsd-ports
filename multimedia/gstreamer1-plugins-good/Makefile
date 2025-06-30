PORTREVISION=	1
CATEGORIES=	multimedia

COMMENT=	GStreamer-plugins good-quality plug-ins

LIB_DEPENDS+=	libnettle.so:security/nettle \
		libsoup-3.0.so:devel/libsoup3

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=			good
GST_PLUGIN=		${DIST}
GST_PLUGIN_SUFFIX=	-${DIST}
NO_GSTREAMER_COMMON=	yes

GOOD_GST_ENABLED_PLUGINS=	adaptivedemux2 \
				alpha \
				apetag \
				audiofx \
				audioparsers \
				auparse \
				autodetect \
				avi \
				cutter \
				deinterlace \
				debugutils \
				dtmf \
				effectv \
				equalizer \
				flv \
				flx \
				goom \
				goom2k1 \
				icydemux \
				id3demux \
				imagefreeze \
				interleave \
				isomp4 \
				law \
				level \
				matroska \
				monoscope \
				multifile \
				multipart \
				nls \
				oss \
				oss4 \
				replaygain \
				rtp \
				rtpmanager \
				rtsp \
				shapewipe \
				smpte \
				spectrum \
				tests \
				udp \
				videobox \
				videocrop \
				videofilter \
				videomixer \
				wavenc \
				wavparse \
				xingmux \
				y4m

.include "${MASTERDIR}/Makefile"
