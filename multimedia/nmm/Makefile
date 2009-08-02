# New ports collection makefile for:	nmm
# Date created:         Apr 21. 2008
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	nmm
PORTVERSION=	1.0.0
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	http://www.motama.com/download/

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	A network-integrated multimedia middleware

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg			\
		png:${PORTSDIR}/graphics/png			\
		mp3lame:${PORTSDIR}/audio/lame			\
		mad:${PORTSDIR}/audio/libmad			\
		dvdread:${PORTSDIR}/multimedia/libdvdread	\
		dvdnav:${PORTSDIR}/multimedia/libdvdnav		\
		vorbis:${PORTSDIR}/audio/libvorbis		\
		MagickCore:${PORTSDIR}/graphics/ImageMagick	\
		cdda_paranoia:${PORTSDIR}/audio/cdparanoia	\
		avcodec:${PORTSDIR}/multimedia/ffmpeg		\
		mpeg2:${PORTSDIR}/multimedia/libmpeg2		\
		a52:${PORTSDIR}/audio/liba52			#\
#		rfftw:${PORTSDIR}/math/fftw			\
#		shout:${PORTSDIR}/audio/libshout		\
#		lirc_client:${PORTSDIR}/comms/lirc

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GNOME=	lthack libxml2	# lthack + autotools stuff below? To verify!
USE_GMAKE=	yes
USE_XORG=	x11

USE_AUTOTOOLS=	libltdl:22 libtool:22 \
		autoconf:262 autoheader:262 \
		automake:19 aclocal:19
ACLOCAL_ARGS=	-I ${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal -I .

CONFIGURE_ARGS=	--program-prefix=nmm- \
		--enable-final \
		--disable-examples-helloworld --disable-examples-avmux \
		--without-alsa \
		--with-ffmpeg=${LOCALBASE} \
		--with-ltdl=${LOCALBASE} \
		--with-dvdread=${LOCALBASE} \
		--with-dvdnav=${LOCALBASE} \
		--with-libpng=${LOCALBASE} --with-png=${LOCALBASE} \
		--with-ImageMagick=${LOCALBASE} \
		--with-extra-includes=${LOCALBASE}/include/ImageMagick \
		--with-mad=${LOCALBASE} \
		--with-lame=${LOCALBASE} \
		--with-cdparanoia=${LOCALBASE} \
		--with-libjpeg=${LOCALBASE} \
		--with-libogg=${LOCALBASE} \
		--with-libvorbis=${LOCALBASE} \
		--with-vorbis=${LOCALBASE} \
		--with-a52dec=${LOCALBASE} \
		--with-mpeg2dec=${LOCALBASE}
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV+=	LIBS="${PTHREAD_LIBS}" CFLAGS="${CFLAGS}"
MAKE_ENV+=	LIBS="${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -i "" -e 's:Magick++ Magick:Magick++ MagickCore:g' \
		${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

#
## TODO
#
# - libraw1394 (SF)
#	for firewire support
# - libliveMedia (live555.com)
#	for RTP
# - dvb?
#	probably not suitable for FreeBSD, alternatively cxm and bt848 support?
# - libshout
# - fftw
#	for audio visualization (spectral analysis)
#	seems to need a more recent gcc, maybe suitable after OPTIONS support
#	in the port so that it is not compiled by default
# - OPTIONS support in the port
# - xml2devel? (2.6.31)
#	enhanced sync support, probably only after it hits the ports collection
#	by default
# - lirc?
# - doxygen?
# - docbook?

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${ARCH} == "amd64" && ${OSVERSION} >= 700000
BROKEN=		ihppimpl segfaults during build
.endif

.include <bsd.port.post.mk>
