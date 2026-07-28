# The information for PORTVERSION and CHROME_VERSION is borrowed from
# https://aur.archlinux.org/cgit/aur.git/?h=vivaldi-widevine
# PORTVERSION can also be obtained from the plugin's manifest.json file

PORTNAME=	widevine-cdm
PORTVERSION=	4.10.3050.0
PORTREVISION=	1
CATEGORIES=	www multimedia linux
MASTER_SITES=	https://dl.google.com/linux/deb/pool/main/g/google-chrome-stable/
PKGNAMEPREFIX=	linux-
DISTNAME=	google-chrome-stable_${CHROME_VERSION}_${ARCH:S/aarch64/arm64/}
EXTRACT_SUFX=	.deb

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Widevine CDM plugin as provided by Google
WWW=		https://www.widevine.com

LICENSE=	Proprietary
LICENSE_NAME=	Google proprietary license
LICENSE_FILE=	${WRKDIR}/opt/google/chrome/WidevineCdm/LICENSE
LICENSE_PERMS=	no-dist-sell no-pkg-sell no-dist-mirror no-pkg-mirror

ONLY_FOR_ARCHS=	aarch64 amd64

NO_BUILD=	yes
PLIST_FILES=	lib/WidevineCdm/_platform_specific/linux_${LINUX_ARCH}/libwidevinecdm.so \
		lib/WidevineCdm/manifest.json

LINUX_ARCH=	${ARCH:S/amd64/x64/:S/aarch64/arm64/}
CHROME_VERSION=	150.0.7871.186-1

.if make(makesum)
.  for arch in ${ONLY_FOR_ARCHS}
DISTFILES+=	google-chrome-stable_${CHROME_VERSION}_${arch:S/aarch64/arm64/}${EXTRACT_SUFX}
.  endfor
.endif

post-extract:
	cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} data.tar.xz ${EXTRACT_AFTER_ARGS}

do-install:
	cd ${WRKDIR}/opt/google/chrome/ && ${COPYTREE_SHARE} WidevineCdm ${STAGEDIR}${PREFIX}/lib
	${RM} ${STAGEDIR}${PREFIX}/lib/WidevineCdm/LICENSE

.include <bsd.port.mk>
