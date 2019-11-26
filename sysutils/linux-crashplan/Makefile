# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	crashplan
DISTVERSION=	4.8.3
CATEGORIES=	sysutils java linux
MASTER_SITES=	https://download.code42.com/installs/linux/install/CrashPlan/
PKGNAMEPREFIX=	linux-
DISTNAME=	CrashPlan_${DISTVERSION}_Linux

MAINTAINER=	subtil@gmail.com
COMMENT=	Backs up data to remote servers or hard drives

BROKEN=		unfetchable

ONLY_FOR_ARCHS=	amd64 i386

RUN_DEPENDS=	bash:shells/bash

USES=		linux shebangfix tar:tgz
USE_LDCONFIG=	yes
USE_LINUX=	expat fontconfig xorglibs
USE_RC_SUBR=	crashplan

USE_JAVA=	yes
JAVA_OS=	linux

WRKSRC=		${WRKDIR}/crashplan-install

SHEBANG_FILES=	scripts/CrashPlanEngine scripts/CrashPlanDesktop

NO_BUILD=	yes

LOGDIR=		/var/log/crashplan

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${STAGEDIR}${DATADIR} && ${CAT} ${WRKSRC}/CrashPlan_${DISTVERSION}.cpi | ${GZIP_CMD} -d -c - | ${CPIO} -i --no-preserve-owner
	@${MV} ${STAGEDIR}${DATADIR}/lang/* ${STAGEDIR}${DATADIR}/conf
	@${RMDIR} ${STAGEDIR}${DATADIR}/lang
	${RLN} ${STAGEDIR}${DATADIR}/conf ${STAGEDIR}${DATADIR}/lang
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/CrashPlanDesktop ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/CrashPlanEngine ${STAGEDIR}${DATADIR}/bin/
	${CP} ${WRKSRC}/scripts/run.conf ${STAGEDIR}${DATADIR}/bin/
	${ECHO_CMD} > ${STAGEDIR}${DATADIR}/install.vars
	${ECHO_CMD} "TARGETDIR=${DATADIR}" >> ${STAGEDIR}${DATADIR}/install.vars
	${ECHO_CMD} "BINSDIR=${DATADIR}/bin" >> ${STAGEDIR}${DATADIR}/install.vars
	${ECHO_CMD} "JAVACOMMON=${JAVA}" >> ${STAGEDIR}${DATADIR}/install.vars
	${ECHO_CMD} "LOGDIR=${LOGDIR}" >> ${STAGEDIR}${DATADIR}/install.vars
	${CAT} ${WRKSRC}/install.defaults >> ${STAGEDIR}${DATADIR}/install.vars

.include <bsd.port.mk>
