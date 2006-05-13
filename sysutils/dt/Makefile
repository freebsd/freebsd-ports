# New ports collection makefile for:    dt
# Date created:         		14 Jan 2004
# Whom:                 		Radim Kolar
#
# $FreeBSD$
#
# $Tecnik: ports/sysutils/dt/Makefile,v 1.3 2005/12/12 19:58:36 itetcu Exp $
#

PORTNAME=	dt
PORTVERSION=	15.14
CATEGORIES=	sysutils
MASTER_SITES=	http://home.comcast.net/~SCSIguy/SCSI_FAQ/RMiller_Tools/ftp/dt/ \
		http://people.tecnik93.com/~itetcu/FreeBSD/ports/${PORTNAME}/sources/
DISTNAME=	dt-source

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Data Test Program - disk/tape error diagnostic tool

WRKSRC=		${WRKDIR}/dt.d
MAKEFILE=	Makefile.freebsd
ALL_TARGET=	dt

PORTDOCS=	README.1st ToDoList WhatsNew-* dt-UsersGuide.txt dt-Overview.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dt ${PREFIX}/sbin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pattern_* ${DATADIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/dta ${WRKSRC}/dtc ${WRKSRC}/dtf ${WRKSRC}/dtr ${WRKSRC}/dts ${WRKSRC}/dtt ${WRKSRC}/dtw ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/MakeTestDisc ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.1st ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ToDoList ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/WhatsNew-* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dt-UsersGuide.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dt.help ${DOCSDIR}/dt-Overview.txt
.endif

.include <bsd.port.mk>
