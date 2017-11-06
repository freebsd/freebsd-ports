# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	dt
PORTVERSION=	17.07
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://home.comcast.net/~SCSIguy/SCSI_FAQ/RMiller_Tools/ftp/dt/ \
		http://ionut.tetcu.info/FreeBSD/ports/distfiles/
#PORTVERSION=	18.32
#MASTER_SITES=	http://www.scsifaq.org/RMiller_Tools/ftp/dt/ \
#		http://dl.dropboxusercontent.com/u/32363629/Datatest/
#DISTNAME=	${PORTNAME}-source-v${PORTVERSION
DISTNAME=	${PORTNAME}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data Test Program - disk/tape error diagnostic tool

LICENSE=	ISCL

OPTIONS_DEFINE=	DOCS

USES=		shebangfix
SHEBANG_FILES=	Scripts/DiskTests.ksh \
		Scripts/butterfly.ksh \
		Scripts/butterfly_file.ksh \
		Scripts/dt_noprog_script.ksh
WRKSRC=		${WRKDIR}/dt.d
MAKEFILE=	Makefile.freebsd
ALL_TARGET=	dt

PORTDOCS=	README.1st ToDoList WhatsNew-* dt-UsersGuide.pdf dt-Overview.txt

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/usr/bin/ksh|${ksh_CMD}|' \
		${WRKSRC}/Scripts/trigger-AIX.ksh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dt ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/pattern_* ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for script in DiskTests.ksh butterfly.ksh butterfly_file.ksh dt_noprog_script.ksh \
	dta dtc dtf dtr dts dtt dtw trigger-AIX.ksh
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/${script} ${STAGEDIR}${EXAMPLESDIR}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.1st \
		${WRKSRC}/ToDoList \
		${WRKSRC}/WhatsNewFiles/WhatsNew-* \
		${WRKSRC}/Documentation/dt-UsersGuide.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/dt.help ${STAGEDIR}${DOCSDIR}/dt-Overview.txt

.include <bsd.port.mk>
