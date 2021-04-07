PORTNAME=	nzbhydra2
DISTVERSION=	3.13.1
DISTVERSIONSUFFIX=	-linux
CATEGORIES=	news java
MASTER_SITES=	https://github.com/theotherp/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	daniel@shafer.cc
COMMENT=	Usenet meta search

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le

USES=		python:3.5+ shebangfix zip
USE_JAVA=	yes
USE_RC_SUBR=	nzbhydra2

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	nzbhydra2 nzbhydra2wrapperPy3.py
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		JAVA=${JAVA}

JAVA_VERSION=	8+
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

do-install:
	@${MKDIR} ${STAGEDIR}/${DATADIR}
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/nzbhydra2wrapperPy3.py ${STAGEDIR}/${DATADIR}

.include <bsd.port.mk>
