# $FreeBSD$

PORTNAME=	nzbhydra2
DISTVERSION=	2.7.2
DISTVERSIONSUFFIX=	-linux
CATEGORIES=	news java
MASTER_SITES=	https://github.com/theotherp/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	daniel@shafer.cc
COMMENT=	Usenet meta search

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

USES=		python:2.7 shebangfix zip
USE_JAVA=	yes
USE_RC_SUBR=	nzbhydra2

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	nzbhydra2 nzbhydra2wrapper.py
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		JAVA=${JAVA}

JAVA_VERSION=	8+
JAVA_VENDOR=	openjdk
JAVA_RUN=	yes

USERS=		nzbhydra2
GROUPS=		nzbhydra2

PLIST_FILES=	${DATADIR}/lib/core-${DISTVERSION}-exec.jar \
		${DATADIR}/nzbhydra2 \
		${DATADIR}/nzbhydra2wrapper.py \
		${DATADIR}/changelog.md \
		${DATADIR}/readme.md \
		${DATADIR}/LICENSE

post-extract:
	# Cleanup unnecessary files
	@${RM} -r ${WRKSRC}/systemd ${WRKSRC}/sysv ${WRKSRC}/rc.d ${WRKSRC}/upstart

do-install:
	@${MKDIR} ${STAGEDIR}/${DATADIR}
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/nzbhydra2wrapper.py ${STAGEDIR}/${DATADIR}

.include <bsd.port.mk>
