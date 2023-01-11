PORTNAME=	pcns
PORTVERSION=	4.4.0
CATEGORIES=	sysutils java
MASTER_SITES=
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	sstallion@gmail.com
COMMENT=	PowerChute Network Shutdown
WWW=		https://www.apc.com/us/en/product-range/61933-powerchute-network-shutdown/

LICENSE=	EULA
LICENSE_NAME=	Royalty-Free PowerChute Network Shutdown (PCNS)
LICENSE_FILE=	${WRKSRC}/group1/EULA/PCNS_EULA_English.txt
LICENSE_PERMS=	none

USE_JAVA=	11+
USE_RC_SUBR=	pcns

SUB_FILES=	pkg-message
SUB_LIST=	JAVA_HOME=${JAVA_HOME} \
		LOGDIR=${LOGDIR}

NO_ARCH=	yes
NO_BUILD=	yes

LOGDIR=		/var/log/${PORTNAME}
WRKSRC=		${WRKDIR}/PowerChute

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE?=You must download PowerChute Network Shutdown for Linux from ${WWW}, extract the archive, place Linux_x64/${DISTNAME}${EXTRACT_SUFX} in ${DISTDIR}, and then run make again
.endif

post-extract:
	@cd ${WRKSRC} && ${RM} *.sh silentInstall* uninstall
	@cd ${WRKSRC}/group1 && ${CP} m11.cfg m11.bak
	@cd ${WRKSRC}/group1/bin && \
		${MV} Linux/notifier.sh notifier && \
		${MV} Linux/shutdown.sh shutdown && \
		${RM} -rf Aix Hpux Linux Solaris VIMA
	@cd ${WRKSRC}/group1/comp/http/html/Help && \
		${MV} Standard/* . && \
		${RMDIR} Standard

post-patch:
	@${REINPLACE_CMD} -e 's|\(<Property name="LOG_DIR">\).\(</Property\)|\1${LOGDIR}\2|' \
		${WRKSRC}/group1/log4j2.xml

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/pcns
	@${INSTALL_SCRIPT} ${WRKDIR}/pcns ${STAGEDIR}${PREFIX}/etc/rc.d
	@cd ${WRKSRC} && ${PAX} -rw . ${STAGEDIR}${PREFIX}/pcns
	@${CHMOD} 660 ${STAGEDIR}${PREFIX}/pcns/group1/*m11*
	@${CHMOD} 660 ${STAGEDIR}${PREFIX}/pcns/group1/pcnsconfig*
	@${INSTALL} -d -m 750 ${STAGEDIR}${LOGDIR}

.include <bsd.port.post.mk>
