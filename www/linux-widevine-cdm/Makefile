# The information for PORTVERSION and CHROME_VERSION is borrowed from
# https://aur.archlinux.org/cgit/aur.git/?h=vivaldi-widevine

PORTNAME=	widevine-cdm
PORTVERSION=	4.10.2710.0
CATEGORIES=	www multimedia linux
MASTER_SITES=	https://dl.google.com/linux/deb/pool/main/g/google-chrome-stable/
PKGNAMEPREFIX=	linux-
DISTNAME=	google-chrome-stable_${CHROME_VERSION}_amd64
EXTRACT_SUFX=	.deb

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Widevine CDM plugin as provided by Google
WWW=		https://www.widevine.com

LICENSE=	Proprietary
LICENSE_NAME=	Google proprietary license
LICENSE_FILE=	${WRKDIR}/opt/google/chrome/WidevineCdm/LICENSE
LICENSE_PERMS=	no-dist-sell no-pkg-sell no-dist-mirror no-pkg-mirror

ONLY_FOR_ARCHS=	amd64

NO_BUILD=	yes
PLIST_FILES=	lib/WidevineCdm/_platform_specific/linux_x64/libwidevinecdm.so \
		lib/WidevineCdm/manifest.json

CHROME_VERSION=	121.0.6167.85-1

post-extract:
	cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} data.tar.xz ${EXTRACT_AFTER_ARGS}

do-install:
	cd ${WRKDIR}/opt/google/chrome/ && ${COPYTREE_SHARE} WidevineCdm ${STAGEDIR}${PREFIX}/lib
	${RM} ${STAGEDIR}${PREFIX}/lib/WidevineCdm/LICENSE

.include <bsd.port.mk>
