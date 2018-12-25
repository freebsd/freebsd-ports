# Created by: alepulver
# $FreeBSD$

PORTNAME=	xrdp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.9
PORTEPOCH=	1
CATEGORIES=	net
DIST_SUBDIR?=	${PORTNAME}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Open source Remote Desktop Protocol (RDP) server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/nasm:devel/nasm
RUN_DEPENDS=	${LOCALBASE}/lib/xorg/modules/libxorgxrdp.so:x11-drivers/xorgxrdp \
		${LOCALBASE}/lib/pulse-12.2/modules/module-xrdp-sink.so:audio/pulseaudio-module-xrdp

USES=		autoreconf:build jpeg localbase libtool pkgconfig ssl
USE_XORG=	ice pixman sm x11 xfixes xrandr
USE_LDCONFIG=	${PREFIX}/lib/xrdp
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
GH_ACCOUNT=	neutrinolabs
GH_PROJECT=	xrdp librfxcodec:librfxcodec libpainter:libpainter
GH_TAGNAME=	v0.1.4:librfxcodec v0.1.1:libpainter

CONFIGURE_ARGS=	--localstatedir=/var --enable-strict-locations \
		--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig \
		--enable-jpeg --enable-pixman --enable-rfxcodec --enable-painter
LDFLAGS+=	-lssl
CONFLICTS=	xrdp-devel[0-9]*
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-deinstall pkg-install pkg-message
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

post-extract:
	# librfxcodec is provided as git submodule
	@${CP} -r ${WRKSRC_librfxcodec}/ ${WRKSRC}/librfxcodec/
	@${CP} -r ${WRKSRC_libpainter}/ ${WRKSRC}/libpainter/

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./bootstrap

post-stage:
	@${RM} ${STAGEDIR}${PREFIX}/etc/xrdp/rsakeys.ini
	@${RM} ${STAGEDIR}${PREFIX}/etc/xrdp/cert.pem
	@${RM} ${STAGEDIR}${PREFIX}/etc/xrdp/key.pem
.for f in sesman.ini startwm.sh reconnectwm.sh xrdp.ini xrdp_keyboard.ini
	@${MV} ${STAGEDIR}${PREFIX}/etc/xrdp/$f ${STAGEDIR}${PREFIX}/etc/xrdp/$f.sample
.endfor

.include <bsd.port.mk>
