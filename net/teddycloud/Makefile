PORTNAME=	teddycloud
DISTVERSIONPREFIX=	tc_v
DISTVERSION=	0.3.5
CATEGORIES=	net
# Get the latest commit hashes here: https://github.com/toniebox-reverse-engineering/tonies-json/commits/release/
# NOTE: remove the existing tonies.json and tonieboxes.json from DISTDIR before you do a `make makesum`
MASTER_SITES=	https://raw.githubusercontent.com/toniebox-reverse-engineering/tonies-json/d3bde1c301cc509ffced79bb08b40ec769029bbe/:toniesjson
DISTFILES=	tonies.json:toniesjson \
		tonieboxes.json:toniesjson
EXTRACT_ONLY=	${DISTFILES:N*\:toniesjson:C/\:.*//}

MAINTAINER=	freebsd@pe82.de
COMMENT=	Alternative cloud server for the Toniebox
WWW=		https://tonies-wiki.revvox.de/docs/tools/teddycloud/

LICENSE=	GPLv2+

BUILD_DEPENDS+= curl:ftp/curl \
		protoc-c:devel/protobuf-c

USES= 		gmake
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
GH_TAGNAME=	v1.7.17:cJSON \
		v1.3.5:ogg \
		v1.4:opus \
		ad73bfa:teddycloud_web \
		v2.3.2:cyclone_common,cyclone_crypto,cyclone_ssl,cyclone_tcp

USE_RC_SUBR=	teddycloudd
MAKE_ENV+=	CONFIG_RUNTIME_BASE_PATH=${PREFIX}/etc/teddycloud \
		RUNTIME_BASE_PATH=${PREFIX}/share/teddycloud
# This did reliably fail due to some unknown deps when using parallel build
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	preinstall

post-extract:

pre-install:
	@${CP} ${DISTFILES:M*\:toniesjson:C/\:.*//:S,^,${_DISTDIR},} ${WRKSRC}/install/pre/config/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/install/pre/teddycloud ${STAGEDIR}${PREFIX}/bin
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
