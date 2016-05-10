# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	crashplan
DISTVERSION=	4.5.0
PORTREVISION=	1
CATEGORIES=	sysutils java linux
MASTER_SITES=	https://download.code42.com/installs/linux/install/CrashPlan/
PKGNAMEPREFIX=	linux-
DISTNAME=	CrashPlan_${DISTVERSION}_Linux

MAINTAINER=	subtil@gmail.com
COMMENT=	Backs up data to remote servers or hard drives

RUN_DEPENDS=	bash:shells/bash

USE_JAVA=	yes
JAVA_OS=	linux
JAVA_VERSION=	1.7+

WRKSRC=		${WRKDIR}/crashplan-install

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
	${ECHO_CMD} "JAVA_COMMON=${JAVA}" >> ${STAGEDIR}${CRASHDIR}/install.vars
	${CAT} ${WRKSRC}/install.defaults >> ${STAGEDIR}${CRASHDIR}/install.vars

.include <bsd.port.mk>
