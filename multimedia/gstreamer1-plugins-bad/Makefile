PORTREVISION=	1
CATEGORIES=	multimedia

COMMENT=	GStreamer-plugins that need more quality, testing or documentation

GST_PLUGIN=	bad
GST_PLUGIN_SUFFIX=	-bad

USES+=	xorg
USE_XORG+=x11

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

DIST=		bad
BAD_GST_ENABLED_PLUGINS=accurip \
			adaptivedemux \
			adpcmdec \
			adpcmenc \
			aes \
			aiff \
			asfmux \
			audio \
			audiobuffersplit \
			audiofxbad \
			audiolatency \
			audiomixmatrix \
			audiovisualizers \
			autoconvert \
			basecamerabinsrc \
			bayer \
			bz2 \
			camerabin2 \
			codecalpha \
			codecparsers \
			codecs \
			codectimestamper \
			coloreffects \
			data \
			debugutils \
			dvbsubenc \
			dvbsuboverlay \
			dvdspu \
			examples \
			faceoverlay \
			festival \
			fieldanalysis \
			freeverb \
			frei0r \
			gaudieffects \
			gdp \
			geometrictransform \
			id3tag \
			insertbin \
			inter \
			interfaces \
			interlace \
			ipcpipeline \
			isoff \
			ivfparse \
			ivtc \
			jp2kdecimator \
			jpegformat \
			librfb \
			midi \
			mpegdemux \
			mpegpsmux \
			mpegts \
			mpegtsdemux \
			mpegtsmux \
			mxf \
			netsim \
			nls \
			onvif \
			pcapparse \
			pkgconfig \
			play \
			player \
			pnm \
			proxy \
			rawparse \
			removesilence \
			rist \
			rtmp2 \
			rtp \
			sctp \
			sdp \
			segmentclip \
			shm \
			siren \
			smooth \
			speed \
			subenc \
			switchbin \
			timecode \
			transcode \
			transcoder \
			uridownloader \
			videofilters \
			videoframe_audiolevel \
			videoparsers \
			videosignal \
			vmnc \
			webrtc \
			y4m

NO_GSTREAMER_COMMON=	yes
PLIST=		${.CURDIR}/pkg-plist

USES+=ssl

.include "${MASTERDIR}/Makefile"

USE_GNOME+=	glib20 gtk30

BUILD_DEPENDS+=	v4l_compat>=1.0.20100321:multimedia/v4l_compat \
	gtk3>=3.10:x11-toolkits/gtk30

LIB_DEPENDS+=libnice.so:net-im/libnice
