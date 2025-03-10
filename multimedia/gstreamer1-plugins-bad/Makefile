PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer-plugins that need more quality, testing or documentation

LIB_DEPENDS+=	libjson-glib-1.0.so:devel/json-glib

USES+=		ssl xorg
USE_GNOME+=	cairo glib20 pango
USE_XORG+=	x11

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=			bad
GST_PLUGIN=		${DIST}
GST_PLUGIN_SUFFIX=	-${DIST}
NO_GSTREAMER_COMMON=	yes

BAD_GST_ENABLED_PLUGINS=accurip \
			adaptivedemux \
			adpcmdec \
			adpcmenc \
			aes \
			aiff \
			analytics \
			analyticsoverlay \
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
			codec2json \
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
			dxva \
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
			mse \
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
			unixfd \
			uridownloader \
			videofilters \
			videoframe_audiolevel \
			videoparsers \
			videosignal \
			vmnc \
			y4m

.include "${MASTERDIR}/Makefile"
