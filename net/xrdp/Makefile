PORTNAME=	xrdp
DISTVERSION=	0.10.4.1
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/neutrinolabs/${PORTNAME}/releases/download/v${DISTVERSION}/
DIST_SUBDIR?=	${PORTNAME}

PATCH_SITES=	https://github.com/neutrinolabs/${PORTNAME}/commit/

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Open source Remote Desktop Protocol (RDP) server
WWW=		https://www.xrdp.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/nasm:devel/nasm
LIB_DEPENDS=	libImlib2.so:graphics/imlib2
RUN_DEPENDS=	${LOCALBASE}/lib/xorg/modules/libxorgxrdp.so:x11-drivers/xorgxrdp \
		xterm:x11/xterm

USES=		autoreconf:build compiler:c11 cpe jpeg libtool localbase \
		pkgconfig ssl xorg
CPE_VENDOR=	neutrinolabs
USE_LDCONFIG=	${PREFIX}/lib/xrdp
USE_XORG=	ice pixman sm x11 xfixes xrandr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-imlib2 \
		--enable-jpeg \
		--enable-painter \
		--enable-pam-config=freebsd \
		--enable-pixman \
		--enable-rfxcodec \
		--enable-strict-locations \
		--enable-vsock \
		--localstatedir=/var \
		--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig

INSTALL_TARGET=	install-strip

LDFLAGS+=	-lssl
CONFLICTS=	xrdp-devel
SUB_FILES=	pkg-deinstall pkg-install pkg-message
SUB_LIST=	OPENSSLBASE=${OPENSSLBASE}

OPTIONS_DEFINE=			DEBUG FUSE IPV6
OPTIONS_DEFAULT=		FDKAAC OPENH264 OPUS X264
OPTIONS_GROUP=			AUDIO_CODEC VIDEO_CODEC
OPTIONS_GROUP_AUDIO_CODEC=	FDKAAC MP3LAME OPUS
OPTIONS_GROUP_VIDEO_CODEC=	OPENH264 X264
FDKAAC_DESC=			Enable Fraunhofer FDK AAC for audio redirection
FUSE_DESC=			Enable drive redirection via FUSE (experimental)
MP3LAME_DESC=			Enable MP3 Lame for audio redirection
OPENH264_DESC=			H.264 video codec support via OpenH264
OPUS_DESC=			Enable Opus for audio redirection

DEBUG_CONFIGURE_ENABLE=		devel-debug devel-logging
FDKAAC_LIB_DEPENDS=		libfdk-aac.so:audio/fdk-aac
FDKAAC_CONFIGURE_ENABLE=	fdkaac
FUSE_USES=			fuse
FUSE_CONFIGURE_ENABLE=		fuse
IPV6_CONFIGURE_ENABLE=		ipv6
MP3LAME_LIB_DEPENDS=		libmp3lame.so:audio/lame
MP3LAME_CONFIGURE_ENABLE=	mp3lame
OPENH264_LIB_DEPENDS=		libopenh264.so:multimedia/openh264
OPENH264_CONFIGURE_ENABLE=	openh264
OPUS_LIB_DEPENDS=		libopus.so:audio/opus
OPUS_CONFIGURE_ENABLE=		opus
X264_LIB_DEPENDS=		libx264.so:multimedia/libx264
X264_CONFIGURE_ENABLE=		x264

GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

GROUP=		_xrdp
USER=		_xrdp

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
# As base OpenSSL doesn't install a .pc file, some flags such as -lcrypto
# cannot be obtained automatically via pkgconfig. When compiled with base
# OpenSSL, it needs to be specified explicitly.
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
.endif

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./bootstrap

post-patch:
	${REINPLACE_CMD} -e "s|^param=Xorg|param=${LOCALBASE}/libexec/Xorg|" \
		${WRKSRC}/sesman/sesman.ini.in
	${REINPLACE_CMD} \
		-e "s|^#runtime_user=xrdp|#runtime_user=_xrdp|" \
		-e "s|^#runtime_group=xrdp|#runtime_group=_xrdp|" \
		${WRKSRC}/xrdp/xrdp.ini.in
	${REINPLACE_CMD} \
		-e "s|^#SessionSockdirGroup=xrdp|#SessionSockdirGroup=_xrdp|" \
		${WRKSRC}/sesman/sesman.ini.in

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/startwm.sh ${STAGEDIR}${ETCDIR}

post-stage:
	@${RM} ${STAGEDIR}${ETCDIR}/rsakeys.ini
	@${RM} ${STAGEDIR}${ETCDIR}/cert.pem
	@${RM} ${STAGEDIR}${ETCDIR}/key.pem
.for f in sesman.ini startwm.sh reconnectwm.sh xrdp.ini xrdp_keyboard.ini \
	gfx.toml
	@${MV} ${STAGEDIR}${ETCDIR}/$f \
		${STAGEDIR}${ETCDIR}/$f.sample
.endfor

.include <bsd.port.post.mk>
