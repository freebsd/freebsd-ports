# New ports collection makefile for:	tik
# Version required:			0.59
# Date created:				13 January 1999
# Whom:					Eugene M. Kim <astralblue@usa.net>
#
# $FreeBSD$
#

DISTNAME=	tik-0.59
CATEGORIES=	net tk82
MASTER_SITES=	http://www.aim.aol.com/tik/ \
		http://www.nectar.com/distfiles/

MAINTAINER=	astralblue@usa.net

RUN_DEPENDS=	tclsh8.2:${PORTSDIR}/lang/tcl82 \
		wish8.2:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/tik
PLIST=		${WRKDIR}/PLIST

SORT?=		sort

SRCDIRS= 	share/tik share/tik/media share/tik/packages
SRCFILES=	media/AOL.gif media/Admin.gif media/DT.gif media/Login.gif \
		media/Logo.gif media/Logout.gif media/Oscar.gif            \
		media/downarrow.gif media/uparrow.gif media/BuddyArrive.au \
		media/BuddyLeave.au media/Pounce.au media/Receive.au       \
		media/Send.au packages/away.tcl packages/imcapture.tcl     \
		packages/mynews.tcl packages/pounce.tcl                    \
		packages/quickchat.tcl packages/search.tcl                 \
		packages/socksproxy.tcl packages/sslproxy.tcl              \
		packages/stock.tcl packages/ticker.tcl sflap.tcl           \
		configTool.tcl toc.tcl tik.tcl tac.tcl sag.tcl
EGDIR=		share/examples/tik
EGFILES=	example.tacrc example.tikpre example.tikrc
DOCDIR=		share/doc/tik
DOCFILES=	CHANGES LICENSE README PROTOCOL

# The packing list starts with just bin/tik.  As we install things,
# build onto the list.
do-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST}
.for d in ${SRCDIRS}
	@${MKDIR} ${PREFIX}/${d}
	@${ECHO} @dirrm ${d} >> ${PLIST}.dirrm
.endfor
.for f in ${SRCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/tik/${f}
	@${ECHO} share/tik/${f} >> ${PLIST}
.endfor
	@${MKDIR} ${PREFIX}/${EGDIR}
	@${ECHO} @dirrm ${EGDIR} >> ${PLIST}.dirrm
.for f in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${EGDIR}/${f}
	@${ECHO} ${EGDIR}/${f} >> ${PLIST}
.endfor
	@${SED} 's#@PREFIX@#${PREFIX}#g' < ${FILESDIR}/tik >${WRKDIR}/tik.sh
	${INSTALL_SCRIPT} ${WRKDIR}/tik.sh ${PREFIX}/bin/tik
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCDIR}
	@${ECHO} @dirrm ${DOCDIR} >> ${PLIST}.dirrm
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${DOCDIR}/${f}
	@${ECHO} ${DOCDIR}/${f} >> ${PLIST}
.endfor
.endif
	@${SORT} -r ${PLIST}.dirrm >> ${PLIST} && ${RM} ${PLIST}.dirrm

.include <bsd.port.mk>
