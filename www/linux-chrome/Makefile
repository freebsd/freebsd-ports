PORTNAME=	chrome
PORTVERSION=	${CHROME_VER}
PORTREVISION=	1
CATEGORIES=	www linux
MASTER_SITES=	https://dl.google.com/linux/chrome/rpm/stable/x86_64/
DISTNAME=	google-${PORTNAME}-stable-${CHROME_VER}-${CHROME_BUILD}.x86_64
PKGNAMEPREFIX=	linux-

MAINTAINER=	chromium@FreeBSD.org
COMMENT=	Google web browser based on WebKit
WWW=		https://www.chromium.org/Home

RUN_DEPENDS=	linux-rl9-wget>0:ftp/linux-rl9-wget \
		linux-rl9-gnupg2>0:security/linux-rl9-gnupg \
		update-mime-database:misc/shared-mime-info

USES=		cpe desktop-file-utils gnome linux:rl9 shared-mime-info shebangfix
USE_LINUX=	alsalib alsa-plugins-oss alsa-plugins-pulseaudio ca-certificates \
		cups-libs curl dbuslibs dri ffmpeg-libs gstreamer1-libav \
		gtk3 libunistring nss p11-kit sqlite3 xorglibs
ONLY_FOR_ARCHS=	amd64

SHEBANG_FILES=	opt/google/chrome/google-chrome

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.rpm
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}

REINPLACE_ARGS=	-i ""

CHROME_VER?=	121.0.6167.160
CHROME_BUILD?=	1

DATADIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

SUB_FILES=	google-chrome

post-extract:
	@${REINPLACE_CMD} -e 's|/usr/bin/google-chrome-stable|${LOCALBASE}/bin/google-chrome|' \
		${WRKSRC}/usr/share/applications/google-chrome.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/google-chrome ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/opt/google && ${CP} -r chrome ${STAGEDIR}${PREFIX}/share
	cd ${WRKSRC}/usr/share && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share
.for sz in 16 24 32 48 64 128 256
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} ${STAGEDIR}${DATADIR}/product_logo_${sz}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/google-chrome.png
.endfor

.include <bsd.port.mk>
