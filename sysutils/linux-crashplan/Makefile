# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	linux-crashplan
DISTVERSION=	3.5.3
CATEGORIES=	sysutils linux
MASTER_SITES=	http://download.crashplan.com/installs/linux/install/CrashPlan/
DISTNAME=	CrashPlan_3.5.3_Linux
EXTRACT_SUFX=	.tgz

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Backs up data to remote servers or hard drives

RUN_DEPENDS=	linux-sun-jre>=0:${PORTSDIR}/java/linux-sun-jre16 \
		bash>=0:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/CrashPlan-install

USE_LINUX=	yes
USE_LINUX_APPS=	expat fontconfig xorglibs
USE_RC_SUBR=	crashplan
USES=		shebangfix

SHEBANG_FILES=	scripts/CrashPlanEngine scripts/CrashPlanDesktop

ONLY_FOR_ARCHS=	i386 amd64

NO_BUILD=	yes
NO_STAGE=	yes

CRASHDIR=	${PREFIX}/share/crashplan

pre-patch:
	@${REINPLACE_CMD} -i '' 's,%%PREFIX%%,${PREFIX},' ${FILESDIR}/patch-CrashPlanDesktop

post-patch:
	@${REINPLACE_CMD} 's/SRV_JAVA_OPTS="/SRV_JAVA_OPTS="-Djava.nio.channels.spi.SelectorProvider=sun.nio.ch.PollSelectorProvider /' ${WRKSRC}/scripts/run.conf
	@${REINPLACE_CMD} 's/GUI_JAVA_OPTS="/GUI_JAVA_OPTS="-Djava.nio.channels.spi.SelectorProvider=sun.nio.ch.PollSelectorProvider /' ${WRKSRC}/scripts/run.conf

do-install:
	@${MKDIR} ${CRASHDIR}
	cd ${CRASHDIR} && ${CAT} ${WRKSRC}/CrashPlan_${DISTVERSION}.cpi | ${GZIP_CMD} -d -c - | ${CPIO} -i --no-preserve-owner
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/CrashPlanDesktop ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/CrashPlanEngine ${CRASHDIR}/bin/
	${CP} ${WRKSRC}/scripts/run.conf ${CRASHDIR}/bin/
	${ECHO_CMD} > ${CRASHDIR}/install.vars
	${ECHO_CMD} "TARGETDIR=${CRASHDIR}" >> ${CRASHDIR}/install.vars
	${ECHO_CMD} "BINSDIR=${CRASHDIR}/bin" >> ${CRASHDIR}/install.vars
	${ECHO_CMD} "JAVACOMMON=${LOCALBASE}/linux-sun-jre1.6.0/bin/java" >> ${CRASHDIR}/install.vars
	${CAT} ${WRKSRC}/install.defaults >> ${CRASHDIR}/install.vars

.include <bsd.port.mk>
