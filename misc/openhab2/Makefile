PORTNAME=	openhab2
PORTVERSION=	2.5.12
#PORTREVISION=	0
CATEGORIES=	misc java
MASTER_SITES=	https://openhab.jfrog.io/artifactory/libs-release-local/org/openhab/distro/openhab/${PORTVERSION}/
DISTNAME=	openhab-${PORTVERSION}

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Vendor and technology agnostic open source smart-home software

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.8
JAVA_RUN=	yes
USE_RC_SUBR=	openhab2
SUB_FILES=	pkg-message update.freebsd
NO_WRKSUBDIR=	yes
NO_ARCH=	yes

USERS=	openhab
GROUPS=	openhab

PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:g" ${WRKSRC}/runtime/bin/setenv

do-build:
.for conf in services/runtime.cfg services/addons.cfg html/index.html transform/en.map transform/de.map
	${MV} ${WRKSRC}/conf/${conf} ${WRKSRC}/conf/${conf}.sample
.endfor
	${RM} -r ${WRKSRC}/runtime/bin/contrib
	${RM} ${WRKSRC}/*.ps1 ${WRKSRC}/*.bat ${WRKSRC}/runtime/bin/*.ps1 ${WRKSRC}/runtime/bin/*.bat \
	    ${WRKSRC}/runtime/bin/*.psm1 \
	    ${WRKSRC}/runtime/bin/setenv.bak \
	    ${WRKSRC}/runtime/bin/setenv.orig

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
	${INSTALL_SCRIPT} ${WRKDIR}/update.freebsd ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/runtime/bin/
	(cd ${WRKSRC}/userdata && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/${PORTNAME})

gen-plist:
	${FIND} ${STAGEDIR} -type f | ${SED} -e "s:${STAGEDIR}${PREFIX}/::g ; s:${PORTVERSION}:%%PORTVERSION%%:g" | ${SORT} -u | ${GREP} libexec/ >pkg-plist.new
	echo '@owner openhab' >>pkg-plist.new
	echo '@group openhab' >>pkg-plist.new
	${FIND} ${STAGEDIR}${DATADIR} -type f | ${SED} -E -e "s:${STAGEDIR}${DATADIR}/(.*):@sample %%DATADIR%%/\\1 /var/db/openhab2/userdata/\\1:g ; s:${PORTVERSION}:%%PORTVERSION%%:g" | ${SORT} -u >>pkg-plist.new
	${FIND} ${STAGEDIR}${ETCDIR} -type d | ${SORT} -u | ${SED} -e "s:${STAGEDIR}${ETCDIR}:@dir %%ETCDIR%%:g ; s:${PORTVERSION}:%%PORTVERSION%%:g"  >>pkg-plist.new
	${FIND} ${STAGEDIR}${ETCDIR} -type f | ${SORT} -u | ${SED} -E -e "s:${STAGEDIR}${ETCDIR}/:%%ETCDIR%%/:g ; s:${PORTVERSION}:%%PORTVERSION%%:g ; s:(.*.sample)$:@sample(openhab,openhab,640) \\1:" >>pkg-plist.new
	${FIND} ${STAGEDIR}/var/db/${PORTNAME} -type d | ${SORT} -ru | ${SED} -e "s:${STAGEDIR}:@dir :g" >>pkg-plist.new
	echo "@dir /var/log/${PORTNAME}" >>pkg-plist.new
	echo "@dir /var/run/${PORTNAME}" >>pkg-plist.new

.include <bsd.port.mk>
