# New ports collection makefile for:    dt
# Date created:         		14 Jan 2004
# Whom:                 		Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	dt
PORTVERSION=	15.6
CATEGORIES=	sysutils
MASTER_SITES=	http://home.comcast.net/~SCSIguy/SCSI_FAQ/RMiller_Tools/ftp/dt/
DISTNAME=	dt-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data Test Program - disk/tape error diagnostic tool

BROKEN=		Size mismatch

USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/dt.d
ALL_TARGET=	dt

PORTDOCS=	README.1st ToDoList WhatsNew-* dt-UsersGuide.txt dt-Overview.txt

post-patch:
	@${CP} ${WRKSRC}/Makefile.freebsd ${WRKSRC}/Makefile

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
