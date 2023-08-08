PORTNAME=	nzbhydra2
DISTVERSION=	4.7.4
DISTVERSIONSUFFIX=	-linux
CATEGORIES=	news java
MASTER_SITES=	https://github.com/theotherp/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	marcel@herrbischoff.com
COMMENT=	Usenet meta search
WWW=		https://github.com/theotherp/nzbhydra2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le

USES=		python zip
USE_JAVA=	yes
USE_RC_SUBR=	nzbhydra2

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	nzbhydra2
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		JAVA=${JAVA}

JAVA_VERSION=	17+
JAVA_VENDOR=	openjdk
JAVA_RUN=	yes

USERS=		nzbhydra2
GROUPS=		nzbhydra2

PLIST_FILES=	${DATADIR}/lib/core-${DISTVERSION}-exec.jar \
		${DATADIR}/nzbhydra2 \
		${DATADIR}/nzbhydra2wrapperPy3.py \
		${DATADIR}/changelog.md \
		${DATADIR}/readme.md \
		${DATADIR}/LICENSE

post-extract:
	# Cleanup unnecessary files
	@${RM} -r ${WRKSRC}/systemd ${WRKSRC}/sysv ${WRKSRC}/rc.d ${WRKSRC}/upstart ${WRKSRC}/nzbhydra2wrapper.py

pre-install:
	# temp fix for https://github.com/theotherp/nzbhydra2/issues/812
	${RM} -r ${WRKSRC}/data

do-install:
	@${MKDIR} ${STAGEDIR}/${DATADIR}
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}

.include <bsd.port.mk>
