PORTNAME=	xrdp
DISTVERSION=	0.10.2
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/neutribolabs/${PORTNAME}/releases/download/v${DISTVERSION}/
DIST_SUBDIR?=	${PORTNAME}

PATCH_SITES=	https://github.com/neutrinolabs/${PORTNAME}/commit/

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Open source Remote Desktop Protocol (RDP) server
WWW=		https://www.xrdp.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/nasm:devel/nasm
RUN_DEPENDS=	${LOCALBASE}/lib/xorg/modules/libxorgxrdp.so:x11-drivers/xorgxrdp \
		xterm:x11/xterm
LIB_DEPENDS=	libImlib2.so:graphics/imlib2 \
		libopenh264.so:multimedia/openh264 \
		libx264.so:multimedia/libx264

USES=		autoreconf:build compiler:c11 cpe jpeg libtool localbase \
		pkgconfig ssl xorg
CPE_VENDOR=	neutrinolabs
USE_XORG=	ice pixman sm x11 xfixes xrandr
USE_LDCONFIG=	${PREFIX}/lib/xrdp

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFIGURE_ARGS=	--enable-openh264 \
		--enable-x264 \
		--enable-imlib2 \
		--enable-jpeg \
		--enable-painter \
		--enable-pam-config=freebsd \
		--enable-pixman \
		--enable-rfxcodec \
		--enable-strict-locations \
		--enable-vsock \
		--localstatedir=/var \
		--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig
LDFLAGS+=	-lssl
CONFLICTS=	xrdp-devel
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-deinstall pkg-install pkg-message
SUB_LIST=	OPENSSLBASE=${OPENSSLBASE}

USER=		_xrdp
GROUP=		_xrdp

OPTIONS_DEFINE=			DEBUG FUSE IPV6
OPTIONS_DEFAULT=		FDKAAC OPUS
OPTIONS_GROUP=			AUDIO_CODEC
OPTIONS_GROUP_AUDIO_CODEC=	FDKAAC MP3LAME OPUS
FDKAAC_DESC=			Enable Fraunhofer FDK AAC for audio redirection
FUSE_DESC=			Enable drive redirection via FUSE (experimental)
MP3LAME_DESC=			Enable MP3 Lame for audio redirection
OPUS_DESC=			Enable Opus for audio redirection

DEBUG_CONFIGURE_ENABLE=		devel-debug devel-logging
FDKAAC_CONFIGURE_ENABLE=	fdkaac
FDKAAC_LIB_DEPENDS=		libfdk-aac.so:audio/fdk-aac
FUSE_CONFIGURE_ENABLE=		fuse
FUSE_USES=			fuse
IPV6_CONFIGURE_ENABLE=		ipv6
MP3LAME_CONFIGURE_ENABLE=	mp3lame
MP3LAME_LIB_DEPENDS=		libmp3lame.so:audio/lame
OPUS_CONFIGURE_ENABLE=		opus
OPUS_LIB_DEPENDS=		libopus.so:audio/opus

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

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/startwm.sh ${STAGEDIR}${ETCDIR}

post-stage:
	@${RM} ${STAGEDIR}${PREFIX}/etc/xrdp/rsakeys.ini
	@${RM} ${STAGEDIR}${PREFIX}/etc/xrdp/cert.pem
	@${RM} ${STAGEDIR}${PREFIX}/etc/xrdp/key.pem
.for f in sesman.ini startwm.sh reconnectwm.sh xrdp.ini xrdp_keyboard.ini gfx.toml
	@${MV} ${STAGEDIR}${PREFIX}/etc/xrdp/$f ${STAGEDIR}${PREFIX}/etc/xrdp/$f.sample
.endfor

.include <bsd.port.post.mk>
