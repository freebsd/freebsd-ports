# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	linux-crashplan
DISTVERSION=	3.6.4
CATEGORIES=	sysutils linux
MASTER_SITES=	http://download.crashplan.com/installs/linux/install/CrashPlan/
DISTNAME=	CrashPlan_${DISTVERSION}_Linux

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Backs up data to remote servers or hard drives

RUN_DEPENDS=	linux-sun-jre17>=0:${PORTSDIR}/java/linux-sun-jre17 \
		bash>=0:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/CrashPlan-install

USE_LINUX=	yes
USE_LINUX_APPS=	expat fontconfig xorglibs
USE_RC_SUBR=	crashplan
USES=		shebangfix tar:tgz

SHEBANG_FILES=	scripts/CrashPlanEngine scripts/CrashPlanDesktop

ONLY_FOR_ARCHS=	i386 amd64

NO_BUILD=	yes

CRASHDIR=	${PREFIX}/share/crashplan

do-install:
	@${MKDIR} ${STAGEDIR}${CRASHDIR}
	cd ${STAGEDIR}${CRASHDIR} && ${CAT} ${WRKSRC}/CrashPlan_${DISTVERSION}.cpi | ${GZIP_CMD} -d -c - | ${CPIO} -i --no-preserve-owner
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/CrashPlanDesktop ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/CrashPlanEngine ${STAGEDIR}${CRASHDIR}/bin/
	${CP} ${WRKSRC}/scripts/run.conf ${STAGEDIR}${CRASHDIR}/bin/
	${ECHO_CMD} > ${STAGEDIR}${CRASHDIR}/install.vars
	${ECHO_CMD} "TARGETDIR=${CRASHDIR}" >> ${STAGEDIR}${CRASHDIR}/install.vars
	${ECHO_CMD} "BINSDIR=${CRASHDIR}/bin" >> ${STAGEDIR}${CRASHDIR}/install.vars
	${ECHO_CMD} "JAVACOMMON=${LOCALBASE}/linux-sun-jre1.7.0/bin/java" >> ${STAGEDIR}${CRASHDIR}/install.vars
	${CAT} ${WRKSRC}/install.defaults >> ${STAGEDIR}${CRASHDIR}/install.vars

.include <bsd.port.mk>
