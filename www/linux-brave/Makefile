PORTNAME=	brave
PORTVERSION=	${BRAVE_VER}
CATEGORIES=	www linux
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}-browser/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-browser-${BRAVE_VER}-${BRAVE_BUILD}
DISTFILES_aarch64?=	${DISTNAME:S/$/${EXTRACT_SUFX_aarch64}/}
DISTFILES_amd64?=	${DISTNAME:S/$/${EXTRACT_SUFX_amd64}/}
EXTRACT_ONLY?=		${DISTFILES_${ARCH}:C/:[^:]+$//}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Brave web browser based on WebKit
WWW=		https://www.brave.com

LICENSE=	MPL20

RUN_DEPENDS=	update-mime-database:misc/shared-mime-info

USES=		cpe desktop-file-utils gnome linux:rl9 shared-mime-info shebangfix
USE_LINUX=	alsalib alsa-plugins-oss alsa-plugins-pulseaudio at-spi2-atk \
		ca-certificates cairo cups-libs curl dbuslibs dri expat \
		ffmpeg-libs gnupg gstreamer1-libav gtk3 libxkbcommon \
		nspr nss p11-kit pango sqlite3 wget xorglibs
ONLY_FOR_ARCHS=	aarch64 amd64

SHEBANG_FILES=	opt/brave.com/brave/brave-browser

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX_aarch64?=	.aarch64.rpm
EXTRACT_SUFX_amd64?=	.x86_64.rpm

REINPLACE_ARGS=	-i ""

BRAVE_VER?=	1.85.111
BRAVE_BUILD?=	1

DATADIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

SUB_FILES=	brave-browser

.if make(makesum) || make(checksum)
_ALL_DISTFILES=		${DISTFILES_aarch64} ${DISTFILES_amd64}
DISTFILES=		${_ALL_DISTFILES:O:u}
.      else
DISTFILES=		${DISTFILES_${ARCH}}
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|/usr/bin/brave-browser-stable|${LOCALBASE}/bin/brave-browser|' \
		${WRKSRC}/usr/share/applications/brave-browser.desktop \
		${WRKSRC}/usr/share/applications/com.brave.Browser.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/brave-browser ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/opt/brave.com && ${CP} -r brave ${STAGEDIR}${PREFIX}/share
	cd ${WRKSRC}/usr/share && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share
.for sz in 16 24 32 48 64 128 256
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} ${STAGEDIR}${DATADIR}/product_logo_${sz}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/brave-browser.png
.endfor
	${MKDIR} ${STAGEDIR}/etc/brave/policies/managed
	${INSTALL_DATA} ${FILESDIR}/brave.json ${STAGEDIR}/etc/brave/policies/managed
	${INSTALL_DATA} ${FILESDIR}/webrtc.json ${STAGEDIR}/etc/brave/policies/managed

.include <bsd.port.mk>
