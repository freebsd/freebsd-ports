# New ports collection makefile for:	vnc
# Date created:		24 February 1998
# Whom:			msmith
#
# $FreeBSD$
#

PORTNAME=	vnc
PORTVERSION=	3.3.7
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.realvnc.com/dist/
DISTNAME=	${PORTNAME}-${PORTVERSION}-unixsrc

MAINTAINER=	james@now.ie
COMMENT=	Display X and Win32 desktops on remote X/Win32/Java displays

GNU_CONFIGURE=	yes
# vnc supplied zlib seg. faults if compiled with -O
CONFIGURE_ARGS=	--with-installed-zlib
USE_REINPLACE=	yes
USE_XLIB=	yes
USE_XPM=	yes

PLIST=		${WRKDIR}/pkg-plist

MAN1=		vncviewer.1 \
		vncpasswd.1 \
		vncconnect.1

.if !defined(WITHOUT_SERVER)
MAN1+=		Xvnc.1 \
		vncserver.1

RUN_DEPENDS+=	xauth:${PORTSDIR}/x11/XFree86-4-clients \
${X11BASE}/lib/X11/fonts/misc/6x13-ISO8859-1.pcf.gz:${PORTSDIR}/x11-fonts/XFree86-4-fontDefaultBitmaps

USE_PERL5_RUN=	yes
.endif

.include <bsd.port.pre.mk>

pre-build:
.if !defined(WITHOUT_SERVER)
	@${ECHO_MSG} "NOTE:"
	@${ECHO_MSG} "   Use 'make -DWITHOUT_SERVER ...' if you do not wish to"
	@${ECHO_MSG} "   compile/install the VNC server components."
	@${ECHO_MSG} ""
.endif

post-build:
.if defined(WITHOUT_SERVER)
	@${ECHO_MSG} "Skipping build of VNC server."
.else
	@cd ${WRKSRC}/Xvnc && make World
.endif

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} -f ${PLIST}
.if !defined(WITHOUT_SERVER)
	@${ECHO_CMD} bin/Xvnc >> ${PLIST}
	@${ECHO_CMD} bin/vncserver >> ${PLIST}
	@${ECHO_CMD} share/vnc/classes/DesCipher.class >> ${PLIST}
	@${ECHO_CMD} share/vnc/classes/animatedMemoryImageSource.class >> ${PLIST}
	@${ECHO_CMD} share/vnc/classes/authenticationPanel.class >> ${PLIST}
	@${ECHO_CMD} share/vnc/classes/clipboardFrame.class >> ${PLIST}
	@${ECHO_CMD} share/vnc/classes/index.vnc >> ${PLIST}
	@${ECHO_CMD} share/vnc/classes/optionsFrame.class >> ${PLIST}
	@${ECHO_CMD} share/vnc/classes/rfbProto.class >> ${PLIST}
	@${ECHO_CMD} share/vnc/classes/shared.vnc >> ${PLIST}
	@${ECHO_CMD} share/vnc/classes/vncCanvas.class >> ${PLIST}
	@${ECHO_CMD} share/vnc/classes/vncviewer.class >> ${PLIST}
	@${ECHO_CMD} share/vnc/classes/vncviewer.jar >> ${PLIST}
	@${ECHO_CMD} @dirrm share/vnc/classes >> ${PLIST}
	@${ECHO_CMD} @dirrm share/vnc >> ${PLIST}
.endif
	@${ECHO_CMD} bin/vncviewer >> ${PLIST}
	@${ECHO_CMD} bin/vncpasswd >> ${PLIST}
	@${ECHO_CMD} bin/vncconnect >> ${PLIST}

do-install:
.if !defined(WITHOUT_SERVER)
	${REINPLACE_CMD} -e 's|/usr/local/vnc/classes|${PREFIX}/share/vnc/classes|g' \
		-e 's|^\#!/usr/bin/perl|\#!${PERL}|g' ${WRKSRC}/vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver ${PREFIX}/bin/vncserver
	${INSTALL_MAN} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc.man ${PREFIX}/man/man1/Xvnc.1
	${INSTALL_MAN} ${WRKSRC}/vncserver.man ${PREFIX}/man/man1/vncserver.1
# Go install Java classes
	${MKDIR} ${PREFIX}/share/vnc
	${CP} -R ${WRKSRC}/classes ${PREFIX}/share/vnc
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${INSTALL_PROGRAM} ${WRKSRC}/vncconnect/vncconnect ${PREFIX}/bin/vncconnect
	${INSTALL_MAN} ${WRKSRC}/vncviewer/vncviewer.man ${PREFIX}/man/man1/vncviewer.1
	${INSTALL_MAN} ${WRKSRC}/vncpasswd/vncpasswd.man ${PREFIX}/man/man1/vncpasswd.1
	${INSTALL_MAN} ${WRKSRC}/vncconnect/vncconnect.man ${PREFIX}/man/man1/vncconnect.1

.include <bsd.port.post.mk>
