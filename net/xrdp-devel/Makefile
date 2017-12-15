# Created by: alepulver
# $FreeBSD$

PORTNAME=	xrdp
PORTVERSION=	0.9.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net
PKGNAMESUFFIX=	-devel
DIST_SUBDIR?=	${PORTNAME}

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Open source Remote Desktop Protocol (RDP) server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

# pulseaudio's built source is required for audio redirection
BUILD_DEPENDS=	${NONEXISTENT}:audio/pulseaudio:configure \
		${LOCALBASE}/bin/nasm:devel/nasm
RUN_DEPENDS=	${LOCALBASE}/lib/xorg/modules/libxorgxrdp.so:x11-drivers/xorgxrdp

USES=		autoreconf:build jpeg libtool pkgconfig ssl
USE_XORG=	ice pixman sm x11 xfixes xrandr
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/xrdp
USE_GITHUB=	yes
GH_ACCOUNT=	neutrinolabs
GH_PROJECT=	xrdp librfxcodec:librfxcodec libpainter:libpainter
GH_TAGNAME=	v0.1.3:librfxcodec v0.1.1:libpainter

CONFIGURE_ARGS=	--localstatedir=/var --enable-strict-locations \
		--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig \
		--enable-jpeg --enable-pixman --enable-rfxcodec --enable-painter
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB} -lssl
CFLAGS+=	-I${LOCALBASE}/include -L${OPENSSLINC}
CONFLICTS=	xrdp-[0-9]*
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-install pkg-message
SUB_LIST=	OPENSSLBASE=${OPENSSLBASE}

OPTIONS_DEFINE=	DEBUG FUSE IPV6
OPTIONS_DEFAULT=	FDKAAC MP3LAME OPUS
OPTIONS_GROUP=	AUDIO_CODEC
OPTIONS_GROUP_AUDIO_CODEC=	FDKAAC MP3LAME OPUS
FDKAAC_DESC=	Enable Fraunhofer FDK AAC for audio redirection
FUSE_DESC=	Enable drive redirection via FUSE (experimental)
MP3LAME_DESC=	Enable MP3 Lame for audio redirection
OPUS_DESC=	Enable Opus for audio redirection

DEBUG_CONFIGURE_ENABLE=	xrdpdebug
FDKAAC_CONFIGURE_ENABLE=	fdkaac
FDKAAC_LIB_DEPENDS=	libfdk-aac.so:audio/fdk-aac
FUSE_CONFIGURE_ENABLE=	fuse
FUSE_USES=		fuse
IPV6_CONFIGURE_ENABLE=	ipv6
MP3LAME_CONFIGURE_ENABLE=	mp3lame
MP3LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
OPUS_CONFIGURE_ENABLE=	opus
OPUS_LIB_DEPENDS=	libopus.so:audio/opus

# don't forget to increase PORTREVISION after pulseaudio update
PULSE_VERSION=	${MAKE} -C ${PORTSDIR}/audio/pulseaudio -VPORTVERSION
PULSE_WRKSRC=	${MAKE} -C ${PORTSDIR}/audio/pulseaudio -VWRKSRC

post-extract:
	# librfxcodec is provided as git submodule
	@${CP} -r ${WRKSRC_librfxcodec}/ ${WRKSRC}/librfxcodec/
	@${CP} -r ${WRKSRC_libpainter}/ ${WRKSRC}/libpainter/

post-patch:
	@${REINPLACE_CMD} \
		-e "s|^PULSE_SCRIPT=/etc/xrdp/pulse/default.pa|PULSE_SCRIPT=${PREFIX}/etc/xrdp/pulse/default.pa|" \
		${WRKSRC}/sesman/sesman.ini
	@${REINPLACE_CMD} \
		-e "s|^PULSE_DIR = .*|PULSE_DIR = `${PULSE_WRKSRC}`|" \
		-e "s|-Wall -O2|-Wall -O2 -I${LOCALBASE}/include|" \
		${WRKSRC}/sesman/chansrv/pulse/Makefile

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./bootstrap

post-build:
	# build pulseaudio module
	@${CP} -r "`${PULSE_WRKSRC}`" ${WRKDIR}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -C sesman/chansrv/pulse

post-install:
	# install pulseaudio module
	${MKDIR} "${STAGEDIR}${PREFIX}/lib/pulse-`${PULSE_VERSION}`/modules/"
.for f in module-xrdp-sink.so module-xrdp-source.so
	${INSTALL_LIB} -m 0755 ${WRKSRC}/sesman/chansrv/pulse/$f \
		"${STAGEDIR}${PREFIX}/lib/pulse-`${PULSE_VERSION}`/modules/"
.endfor
	# substitute pkg-plist not using PLIST_SUB
	${REINPLACE_CMD} -e "s|%%PULSE_VERSION%%|`${PULSE_VERSION}`|g" ${TMPPLIST}

post-stage:
	@${RM} ${STAGEDIR}${PREFIX}/etc/xrdp/rsakeys.ini
	@${RM} ${STAGEDIR}${PREFIX}/etc/xrdp/cert.pem
	@${RM} ${STAGEDIR}${PREFIX}/etc/xrdp/key.pem
.for f in sesman.ini startwm.sh reconnectwm.sh xrdp.ini xrdp_keyboard.ini
	@${MV} ${STAGEDIR}${PREFIX}/etc/xrdp/$f ${STAGEDIR}${PREFIX}/etc/xrdp/$f.sample
.endfor

.include <bsd.port.mk>
