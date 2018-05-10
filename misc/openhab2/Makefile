# Created by: Alexander Leidinger
# $FreeBSD$

PORTNAME=	openhab2
PORTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	misc java
MASTER_SITES=	https://bintray.com/openhab/mvn/download_file?file_path=org%2Fopenhab%2Fdistro%2Fopenhab%2F${PORTVERSION}/
DISTNAME=	openhab-${PORTVERSION}

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Vendor and technology agnostic open source smart-home software

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USE_JAVA=	yes
JAVA_VERSION=	1.8
JAVA_RUN=	yes
USE_RC_SUBR=	openhab2
SUB_FILES=	pkg-message
NO_WRKSUBDIR=	yes
NO_ARCH=	yes

USERS=	openhab
GROUPS=	openhab

post-patch:
	@${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:g" ${WRKSRC}/runtime/bin/setenv

do-build:
.for conf in services/runtime.cfg services/addons.cfg html/index.html transform/en.map transform/de.map
	${MV} ${WRKSRC}/conf/${conf} ${WRKSRC}/conf/${conf}.sample
.endfor
	${RM} -r ${WRKSRC}/runtime/bin/contrib
	${RM} ${WRKSRC}/*.ps1 ${WRKSRC}/*.bat ${WRKSRC}/runtime/bin/*.ps1 ${WRKSRC}/runtime/bin/*.bat

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}/home
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}/persistence
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}/persistence/db4o
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}/persistence/rrd4j
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}/persistence/mapdb
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}/backups
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}/userdata
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}/userdata/etc
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}/userdata/etc/scripts
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}/userdata/tmp
	${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}
	(cd ${WRKSRC}/conf && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/etc/${PORTNAME})
	(cd ${WRKSRC} && ${COPYTREE_BIN} runtime ${STAGEDIR}${PREFIX}/libexec/${PORTNAME})
	(cd ${WRKSRC} && ${COPYTREE_BIN} addons ${STAGEDIR}${PREFIX}/libexec/${PORTNAME})
.for script in start.sh start_debug.sh
	${INSTALL_SCRIPT} ${WRKSRC}/${script} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/
.endfor
	(cd ${WRKSRC}/userdata && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/${PORTNAME})

.include <bsd.port.mk>
