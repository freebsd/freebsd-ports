PORTNAME=	teddycloud
DISTVERSIONPREFIX=	tc_v
DISTVERSION=	0.6.7
CATEGORIES=	net
# Get the latest commit hashes here: https://github.com/toniebox-reverse-engineering/tonies-json/commits/release/
# NOTE: remove the existing tonies.json and tonieboxes.json from DISTDIR before you do a `make makesum`
MASTER_SITES=	https://raw.githubusercontent.com/toniebox-reverse-engineering/tonies-json/cd5f06d9183470867822d0773ddc0de519d3d46e/:toniesjson
DISTFILES=	tonies.json:toniesjson \
		tonieboxes.json:toniesjson
EXTRACT_ONLY=	${DISTFILES:N*\:toniesjson:C/\:.*//}

MAINTAINER=	freebsd@pe82.de
COMMENT=	Alternative cloud server for the Toniebox
WWW=		https://tonies-wiki.revvox.de/docs/tools/teddycloud/

LICENSE=	GPLv2+

NOT_FOR_ARCHS=		armv6 armv7 i386 powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	32bit targets do not build due to type issues. Upstream library assumes FreeBSD to be 64bit.

BUILD_DEPENDS=	curl:ftp/curl \
		protoc-c:devel/protobuf-c

LIB_DEPENDS=	libcjson.so:devel/libcjson \
		libogg.so:audio/libogg \
		libopus.so:audio/opus

USES=		dos2unix gmake
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	toniebox-reverse-engineering:DEFAULT,teddycloud_web \
		Oryx-Embedded:cyclone_common,cyclone_crypto,cyclone_ssl,cyclone_tcp
GH_PROJECT=	teddycloud_web:teddycloud_web \
		Common:cyclone_common CycloneCRYPTO:cyclone_crypto \
		CycloneSSL:cyclone_ssl CycloneTCP:cyclone_tcp
GH_SUBDIR=	teddycloud_web:teddycloud_web \
		cyclone/common:cyclone_common cyclone/cyclone_crypto:cyclone_crypto \
		cyclone/cyclone_ssl:cyclone_ssl cyclone/cyclone_tcp:cyclone_tcp
# find versions here clone the repository and switch to tag
# git submodule update
# git submodule
GH_TAGNAME=	tcw_v${DISTVERSION}:teddycloud_web \
		v2.4.4:cyclone_common,cyclone_crypto,cyclone_ssl,cyclone_tcp

USE_RC_SUBR=	teddycloudd
MAKE_ENV+=	CONFIG_RUNTIME_BASE_PATH=${PREFIX}/etc/teddycloud \
		RUNTIME_BASE_PATH=${PREFIX}/share/teddycloud \
		NO_SANITIZERS=1 \
		GIT_DIRTY=0 \
		GIT_BUILD_TIME="2026-01-11 11:47:28 +0000" \
		GIT_SHORT_SHA=5b59a82 \
		GIT_SHA=5b59a82ae6c2fd8d8501ea0fe1da2e775fb8eff0 \
		GIT_TAG=tc_v${DISTVERSION} \
		WEB_GIT_DIRTY=0 \
		WEB_GIT_BUILD_TIME="2026-01-11 12:46:00 +0100" \
		WEB_GIT_SHORT_SHA=fa6babd \
		WEB_GIT_SHA=fa6babd8487afba90e391f23714d8435574562a5 \
		WEB_GIT_TAG=tcw_v${DISTVERSION}
# This did reliably fail due to some unknown deps when using parallel build
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	preinstall

pre-install:
	@${CP} ${DISTFILES:M*\:toniesjson:C/\:.*//:S,^,${_DISTDIR}/,} ${WRKSRC}/install/pre/config/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/install/pre/teddycloud ${STAGEDIR}${PREFIX}/bin
	@(cd ${WRKSRC}/install/pre && \
		${COPYTREE_SHARE} "certs data" ${STAGEDIR}${DATADIR})
	@(cd ${WRKSRC}/install/pre/config && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
