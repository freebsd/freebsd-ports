PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer-plugins good-quality plug-ins

GST_PLUGIN=	good
GST_PLUGIN_SUFFIX=	-good

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

DIST=	good

PLIST=		${.CURDIR}/pkg-plist
PATCHDIR=	${.CURDIR}/files
NO_GSTREAMER_COMMON=	yes

GOOD_GST_ENABLED_PLUGINS=	alpha \
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
				y4m

.include "${MASTERDIR}/Makefile"
