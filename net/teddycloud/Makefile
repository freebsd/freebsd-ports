PORTNAME=	teddycloud
DISTVERSIONPREFIX=	tc_v
DISTVERSION=	0.6.3
CATEGORIES=	net
# Get the latest commit hashes here: https://github.com/toniebox-reverse-engineering/tonies-json/commits/release/
# NOTE: remove the existing tonies.json and tonieboxes.json from DISTDIR before you do a `make makesum`
MASTER_SITES=	https://raw.githubusercontent.com/toniebox-reverse-engineering/tonies-json/85a888e355f20ef300e581ad11feb4ac623e62d6/:toniesjson
DISTFILES=	tonies.json:toniesjson \
		tonieboxes.json:toniesjson
EXTRACT_ONLY=	${DISTFILES:N*\:toniesjson:C/\:.*//}

MAINTAINER=	freebsd@pe82.de
COMMENT=	Alternative cloud server for the Toniebox
WWW=		https://tonies-wiki.revvox.de/docs/tools/teddycloud/

LICENSE=	GPLv2+

NOT_FOR_ARCHS=		armv6 armv7 i386 powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	32bit targets do not build due to type issues, upstream library assumes FreeBSD to be 64bit

BUILD_DEPENDS+=	curl:ftp/curl \
		protoc-c:devel/protobuf-c

USES=		gmake
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	toniebox-reverse-engineering:DEFAULT,teddycloud_web \
			DaveGamble:cJSON \
			xiph:ogg,opus \
			Oryx-Embedded:cyclone_common,cyclone_crypto,cyclone_ssl,cyclone_tcp
GH_PROJECT=	cJSON:cJSON ogg:ogg opus:opus teddycloud_web:teddycloud_web \
			Common:cyclone_common CycloneCRYPTO:cyclone_crypto \
			CycloneSSL:cyclone_ssl CycloneTCP:cyclone_tcp
GH_SUBDIR=	cJSON:cJSON ogg:ogg opus:opus teddycloud_web:teddycloud_web \
			cyclone/common:cyclone_common cyclone/cyclone_crypto:cyclone_crypto \
			cyclone/cyclone_ssl:cyclone_ssl cyclone/cyclone_tcp:cyclone_tcp
# find versions here clone the repository and switch to tag
# git submodule update
# git submodule
GH_TAGNAME=	v1.7.15-33-gacc7623:cJSON \
		v1.3.5-9-gdb5c7a4:ogg \
		v1.4-7-g101a71e0:opus \
		tcw_v0.6.3:teddycloud_web \
		v2.3.2:cyclone_common,cyclone_crypto,cyclone_ssl,cyclone_tcp

USE_RC_SUBR=	teddycloudd
MAKE_ENV+=	CONFIG_RUNTIME_BASE_PATH=${PREFIX}/etc/teddycloud \
		RUNTIME_BASE_PATH=${PREFIX}/share/teddycloud \
		NO_SANITIZERS=1 \
		GIT_DIRTY=0 \
		GIT_BUILD_TIME="2025-01-06 08:31:53 +0000" \
		GIT_SHORT_SHA=39b2f89 \
		GIT_SHA=39b2f89bb0c4f7e40cea0efdced012c5715c1f59 \
		GIT_TAG=tc_v0.6.3 \
		WEB_GIT_DIRTY=0 \
		WEB_GIT_BUILD_TIME="2025-01-06 09:28:23 +0100" \
		WEB_GIT_SHORT_SHA=514140d \
		WEB_GIT_SHA=514140d169f5e821299a452fa33dac155eef3a85 \
		WEB_GIT_TAG=tcw_v0.6.3
# This did reliably fail due to some unknown deps when using parallel build
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	preinstall

post-extract:

pre-install:
	@${CP} ${DISTFILES:M*\:toniesjson:C/\:.*//:S,^,${_DISTDIR},} ${WRKSRC}/install/pre/config/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/install/pre/teddycloud ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/certs
	@(cd ${WRKSRC}/install/pre/certs && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/certs)
	@${MKDIR} ${STAGEDIR}${DATADIR}/data
	@(cd ${WRKSRC}/install/pre/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/data)
	@${MKDIR} ${STAGEDIR}${DATADIR}/certs
	@(cd ${WRKSRC}/install/pre/certs && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/certs)
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/teddycloud
	@(cd ${WRKSRC}/install/pre/config && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/etc/teddycloud)

.include <bsd.port.mk>
