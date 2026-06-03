PORTNAME=	nzbhydra2
DISTVERSION=	8.5.3
DISTVERSIONSUFFIX=	-generic
CATEGORIES=	news java
MASTER_SITES=	https://github.com/theotherp/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	marcel@herrbischoff.com
COMMENT=	Usenet meta search
WWW=		https://github.com/theotherp/nzbhydra2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le

USES=		java python zip
JAVA_VERSION=	17
JAVA_VENDOR=	openjdk
USE_RC_SUBR=	nzbhydra2

EXTRACT_BEFORE_ARGS=	-qo \
			-x '*.exe' -x '*.cmd' \
			-x WindowsService \
			-x executables \
			-x nzbhydra2wrapper.py \
			-x other/* -x other
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	nzbhydra2
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		JAVA=${JAVA} \
		DISTVERSION=${DISTVERSION} \
		USER=${USERS} \
		GROUP=${GROUPS}

NO_WRKSUBDIR=	yes

USERS=		nzbhydra2
GROUPS=		nzbhydra2

PLIST_FILES=	${DATADIR}/changelog.md \
		${DATADIR}/lib/core-${DISTVERSION}-exec.jar \
		${DATADIR}/nzbhydra2wrapperPy3.py \
		${DATADIR}/readme.md

do-install:
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}/${DATADIR} '! -name LICENSE')

.include <bsd.port.mk>
