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

WRKSRC=		${WRKDIR}/dt.d
MAKEFILE=	Makefile.freebsd
ALL_TARGET=	dt
LICENSE=	BSD

PORTDOCS=	README.1st ToDoList WhatsNew-* dt-UsersGuide.pdf dt-Overview.txt

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dt ${PREFIX}/sbin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/pattern_* ${DATADIR}
	${MKDIR} ${EXAMPLESDIR}
.for script in DiskTests.ksh butterfly.ksh butterfly_file.ksh dt_noprog_script.ksh \
	dta dtc dtf dtr dts dtt dtw trigger-AIX.ksh
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/${script} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.1st ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ToDoList ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/WhatsNewFiles/WhatsNew-* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/dt-UsersGuide.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/dt.help ${DOCSDIR}/dt-Overview.txt
.endif

.include <bsd.port.mk>
