# New ports collection makefile for:	tik
# Date created:				13 January 1999
# Whom:					Eugene M. Kim <astralblue@usa.net>
#
# $FreeBSD$
#

PORTNAME=	tik
PORTVERSION=	0.87
CATEGORIES=	net tk82
MASTER_SITES=	http://download.sourceforge.net/tik/ \
		http://anti-aol.org/dionysos/l33t_filez/

MAINTAINER=	astralblue@usa.net

RUN_DEPENDS=	tclsh8.2:${PORTSDIR}/lang/tcl82 \
		wish8.2:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/tik
PLIST=		${WRKDIR}/PLIST

SORT?=		sort

SRCDIRS= 	share/tik share/tik/media share/tik/packages share/tik/strs
SRCFILES=	media/AOL.gif media/Admin.gif media/Away.gif media/DT.gif  \
		media/DoorSlam.wav media/Icon.gif media/Idle.gif           \
		media/Pounce.wav media/Login.gif media/add.gif             \
		media/angel.gif media/back.gif media/bigsmile.gif          \
		media/block.gif media/bold.gif media/bsmile.gif            \
		media/burp.gif media/chat.gif media/close.gif              \
		media/color.gif media/crossedlips.gif media/cry.gif        \
		media/delete.gif media/dooropen.wav media/embarrassed.gif  \
		media/font.gif media/ignore.gif media/im.gif               \
		media/imrcv.wav media/imsend.wav media/info.gif            \
		media/invite.gif media/italic.gif media/kiss.gif           \
		media/moneymouth.gif media/ok.gif media/ring.wav           \
		media/sad.gif media/scream.gif media/send.gif              \
		media/smile.gif media/smile8.gif media/strike.gif          \
		media/think.gif media/tongue.gif media/underline.gif       \
		media/warn.gif media/whisper.gif media/wink.gif            \
		media/Logo.gif media/Logout.gif media/Oscar.gif            \
		media/downarrow.gif media/uparrow.gif media/BuddyArrive.au \
		media/BuddyLeave.au media/Receive.au media/yell.gif        \
		media/Send.au						   \
		packages/HTTPProxy.tcl packages/away.tcl packages/beat.tcl \
		packages/bcast.tcl packages/boxinfo.tcl			   \
		packages/buddylog.tcl packages/chatcapture.tcl		   \
		packages/control.tcl packages/dir.tcl packages/getaway.tcl \
		packages/filetrans.tcl packages/imcapture.tcl		   \
		packages/mynews.tcl packages/pounce.tcl                    \
		packages/quickchat.tcl packages/search.tcl                 \
		packages/remoteadmin.tcl packages/remotegui.tcl  	   \
		packages/socksproxy.tcl packages/sslproxy.tcl              \
		packages/ticker.tcl strs/English.strs sflap.tcl            \
		buddylist.tcl buddymgmt.tcl callbacks.tcl chat.tcl	   \
		configandpkg.tcl im.tcl info.tcl popup.tcl preproc.tcl	   \
		protocol.tcl proxy.tcl ui.tcl util.tcl version.tcl	   \
		configTool.tcl toc.tcl tik.tcl sag.tcl
EGDIR=		share/examples/tik
EGFILES=	example.tikstrs example.tikpre example.tikrc
DOCDIR=		share/doc/tik
DOCFILES=	CHANGES CONTRIBUTORS COPYING LICENSE README-LANG	   \
		NEW-FEATURES TODO

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
