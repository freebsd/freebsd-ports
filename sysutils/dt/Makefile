# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	dt
PORTVERSION=	17.07
CATEGORIES=	sysutils
MASTER_SITES=	http://home.comcast.net/~SCSIguy/SCSI_FAQ/RMiller_Tools/ftp/dt/ \
		http://T32.TecNik93.com/FreeBSD/ports/dt/sources/
DISTNAME=	${PORTNAME}-source

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Data Test Program - disk/tape error diagnostic tool

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/dt.d
MAKEFILE=	Makefile.freebsd
ALL_TARGET=	dt
LICENSE=	ISCL

PORTDOCS=	README.1st ToDoList WhatsNew-* dt-UsersGuide.pdf dt-Overview.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dt ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/pattern_* ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for script in DiskTests.ksh butterfly.ksh butterfly_file.ksh dt_noprog_script.ksh \
	dta dtc dtf dtr dts dtt dtw trigger-AIX.ksh
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/${script} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.1st \
		${WRKSRC}/ToDoList \
		${WRKSRC}/WhatsNewFiles/WhatsNew-* \
		${WRKSRC}/Documentation/dt-UsersGuide.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/dt.help ${STAGEDIR}${DOCSDIR}/dt-Overview.txt

.include <bsd.port.mk>
