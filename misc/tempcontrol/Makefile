# Created by: grog@
# $FreeBSD$

PORTNAME=	tempcontrol
PORTVERSION=	1.2
CATEGORIES=	misc
MASTER_SITES=	http://www.lemis.com/grog/brewing/src/brewing/tempcontrol/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Temperature control for fermenting beer and other applications

PLIST_FILES=	bin/tempcontrol share/tempcontrol/temperaturecontrolrc.sample \
		etc/rc.d/temperaturecontrol.sh.sample
PLIST_DIRS=	share/tempcontrol

MAKE_JOBS_UNSAFE=	yes
NO_WRKSUBDIR=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tempcontrol ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/tempcontrol
	${INSTALL_DATA} ${WRKSRC}/temperaturecontrolrc.sample ${PREFIX}/share/tempcontrol
	${INSTALL_SCRIPT} ${WRKSRC}/temperaturecontrol.sh.sample ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
