PORTNAME=	brave
PORTVERSION=	${BRAVE_VER}
PORTREVISION=	1
CATEGORIES=	www linux
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}-browser/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-browser-${BRAVE_VER}-${BRAVE_BUILD}
DISTFILES=	${DISTNAME}.${ARCH:S,amd64,x86_64,}.rpm
.if make(makesum) || make(checksum)
DISTFILES=	${DISTNAME}.aarch64.rpm \
		${DISTNAME}.x86_64.rpm
.endif

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Brave web browser based on WebKit
WWW=		https://www.brave.com

LICENSE=	MPL20

ONLY_FOR_ARCHS=	aarch64 amd64

RUN_DEPENDS=	dbus-run-session:devel/dbus

USES=		cpe desktop-file-utils gnome linux:rl9 shebangfix
USE_LINUX=	alsa-plugins-oss alsa-plugins-pulseaudio alsalib at-spi2-atk \
		ca-certificates cairo cups-libs curl dbuslibs dri expat \
		ffmpeg-libs gnupg gstreamer1-libav gtk3 libxkbcommon nspr nss \
		p11-kit pango sqlite3 wget xorglibs

SHEBANG_FILES=	opt/brave.com/brave/brave-browser

REINPLACE_ARGS=	-i ""
NO_BUILD=	yes
SUB_FILES=	brave-browser

NO_WRKSUBDIR=	yes

BRAVE_VER?=	1.94.117
BRAVE_BUILD?=	1

OPTIONS_DEFINE=		DOCS WIDEVINE
OPTIONS_DEFAULT=	WIDEVINE
OPTIONS_SUB=		yes

WIDEVINE_DESC=	DRM playback via www/linux-widevine-cdm (Netflix etc.)
WIDEVINE_USES=	python:3.11+,run

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWIDEVINE}
SUB_FILES+=	brave-widevine-seed
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|/usr/bin/brave-browser-stable|${LOCALBASE}/bin/brave-browser|' \
		${WRKSRC}/usr/share/applications/brave-browser.desktop \
		${WRKSRC}/usr/share/applications/com.brave.Browser.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/brave-browser ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/opt/brave.com && ${CP} -R brave ${STAGEDIR}${PREFIX}/share
	cd ${WRKSRC}/usr/share && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share
.for sz in 16 24 32 48 64 128 256
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${INSTALL_DATA} ${STAGEDIR}${DATADIR}/product_logo_${sz}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/brave-browser.png
.endfor
	${MKDIR} ${STAGEDIR}/etc/brave/policies/managed
	${INSTALL_DATA} ${FILESDIR}/brave.json ${STAGEDIR}/etc/brave/policies/managed
	${INSTALL_DATA} ${FILESDIR}/webrtc.json ${STAGEDIR}/etc/brave/policies/managed

post-install-WIDEVINE-on:
	${RM} -rf ${STAGEDIR}${DATADIR}/WidevineCdm
	${LN} -sf ${LOCALBASE}/lib/WidevineCdm ${STAGEDIR}${DATADIR}/WidevineCdm
	${INSTALL_SCRIPT} ${WRKDIR}/brave-widevine-seed ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
