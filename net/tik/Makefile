# New ports collection makefile for:	tik
# Version required:	0.51beta
# Date created:		19 December 1998
# Whom:			Peter Doshi <pdoshi01@student.vill.edu>
#
# $Id$
#

DISTNAME=	tik-0.51
CATEGORIES=	net tk80
MASTER_SITES=	http://www.aim.aol.com/tik/

MAINTAINER=	ports@FreeBSD.ORG

RUN_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80 \
		wish8.0:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		${WRKDIR}/tik
BINDIR=		${PREFIX}/bin
NO_BUILD=	yes

do-install:
	${MKDIR}	${PREFIX}/share/tik
	${MKDIR}	${PREFIX}/share/tik/media
	${MKDIR}	${PREFIX}/share/tik/packages
	${INSTALL_DATA} ${WRKSRC}/CHANGES	${PREFIX}/share/tik
	${INSTALL_DATA} ${WRKSRC}/LICENSE	${PREFIX}/share/tik
	${INSTALL_DATA} ${WRKSRC}/PROTOCOL	${PREFIX}/share/tik
	${INSTALL_DATA} ${WRKSRC}/README	${PREFIX}/share/tik
	${INSTALL_SCRIPT} ${WRKSRC}/configTool.tcl	${PREFIX}/share/tik
	${INSTALL_DATA} ${WRKSRC}/example.tacrc	${PREFIX}/share/tik
	${INSTALL_DATA} ${WRKSRC}/example.tikpre	${PREFIX}/share/tik
	${INSTALL_DATA} ${WRKSRC}/example.tikrc	${PREFIX}/share/tik
	${INSTALL_SCRIPT} ${WRKSRC}/sag.tcl       ${PREFIX}/share/tik
	${INSTALL_SCRIPT} ${WRKSRC}/sflap.tcl     ${PREFIX}/share/tik
	${INSTALL_SCRIPT} ${WRKSRC}/tac.tcl       ${PREFIX}/share/tik
	${INSTALL_SCRIPT} ${WRKSRC}/tik.tcl       ${PREFIX}/share/tik
	${INSTALL_SCRIPT} ${WRKSRC}/toc.tcl       ${PREFIX}/share/tik
	${INSTALL_DATA} ${WRKSRC}/media/AOL.gif ${PREFIX}/share/tik/media
	${INSTALL_DATA} ${WRKSRC}/media/Admin.gif       ${PREFIX}/share/tik/media
	${INSTALL_DATA} ${WRKSRC}/media/BuddyArrive.au  ${PREFIX}/share/tik/media
	${INSTALL_DATA} ${WRKSRC}/media/BuddyLeave.au   ${PREFIX}/share/tik/media
	${INSTALL_DATA} ${WRKSRC}/media/DT.gif	  ${PREFIX}/share/tik/media
	${INSTALL_DATA} ${WRKSRC}/media/Login.gif       ${PREFIX}/share/tik/media
	${INSTALL_DATA} ${WRKSRC}/media/Logo.gif	${PREFIX}/share/tik/media
	${INSTALL_DATA} ${WRKSRC}/media/Logout.gif      ${PREFIX}/share/tik/media
	${INSTALL_DATA} ${WRKSRC}/media/Oscar.gif       ${PREFIX}/share/tik/media
	${INSTALL_DATA} ${WRKSRC}/media/Pounce.au       ${PREFIX}/share/tik/media
	${INSTALL_DATA} ${WRKSRC}/media/Receive.au      ${PREFIX}/share/tik/media
	${INSTALL_DATA} ${WRKSRC}/media/Send.au	 ${PREFIX}/share/tik/media
	${INSTALL_DATA} ${WRKSRC}/media/downarrow.gif   ${PREFIX}/share/tik/media
	${INSTALL_DATA} ${WRKSRC}/media/uparrow.gif     ${PREFIX}/share/tik/media
	${INSTALL_SCRIPT} ${WRKSRC}/packages/away.tcl     ${PREFIX}/share/tik/packages
	${INSTALL_SCRIPT} ${WRKSRC}/packages/imcapture.tcl   ${PREFIX}/share/tik/packages
	${INSTALL_SCRIPT} ${WRKSRC}/packages/mynews.tcl    ${PREFIX}/share/tik/packages
	${INSTALL_SCRIPT} ${WRKSRC}/packages/pounce.tcl    ${PREFIX}/share/tik/packages
	${INSTALL_SCRIPT} ${WRKSRC}/packages/search.tcl    ${PREFIX}/share/tik/packages
	${INSTALL_SCRIPT} ${WRKSRC}/packages/socksproxy.tcl   ${PREFIX}/share/tik/packages
	${INSTALL_SCRIPT} ${WRKSRC}/packages/sslproxy.tcl     ${PREFIX}/share/tik/packages
	${INSTALL_SCRIPT} ${WRKSRC}/packages/stock.tcl    ${PREFIX}/share/tik/packages
	${INSTALL_SCRIPT} ${WRKSRC}/packages/ticker.tcl   ${PREFIX}/share/tik/packages

post-install:
	ln -sf ${PREFIX}/share/tik/tik.tcl ${BINDIR}/tik

.include <bsd.port.mk>
