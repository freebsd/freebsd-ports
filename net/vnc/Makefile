# New ports collection makefile for:	vnc
# Date created:		24 February 1998
# Whom:			msmith
#
# $FreeBSD$
#

PORTNAME=	vnc
PORTVERSION=	4.1.1
CATEGORIES=	net ipv6
# This is a placeholder MASTER_SITES entry -- see the pre-fetch target.
MASTER_SITES=	http://www.realvnc.com/:vnc
.if !defined(WITHOUT_SERVER)
MASTER_SITES+=	${MASTER_SITE_XFREE:S/$/:x/}
MASTER_SITE_SUBDIR+=	4.3.0/:x
.endif
DISTNAME=	vnc-4_1_1-unixsrc
DISTFILES=	vnc-4_1_1-unixsrc.tar.gz:vnc
.if !defined(WITHOUT_SERVER)
DISTFILES+=	X430src-1.tgz:x \
		X430src-2.tgz:x \
		X430src-3.tgz:x
.endif
DIST_SUBDIR=	xc

MAINTAINER=	james@now.ie
COMMENT=	Display X and Win32 desktops on remote X/Win32/Java displays

.if !defined(WITHOUT_SERVER)
RUN_DEPENDS=	xauth:${X_CLIENTS_PORT} \
		${X11BASE}/lib/X11/fonts/misc/6x13-ISO8859-1.pcf.gz:${X_FONTS_MISC_PORT}

USE_PERL5=	yes

EXTRA_PATCHES=	${WRKSRC}/xc.patch \
		${PATCHDIR}/vnc.def-patch \
		${PATCHDIR}/FreeBSD.cf-patch
.endif

GNU_CONFIGURE=	yes
# The vnc supplied zlib seg. faults if compiled with -O
CONFIGURE_ARGS=	--with-installed-zlib
USE_GCC=	3.4
USE_REINPLACE=	yes
USE_XLIB=	yes
USE_XPM=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
PLIST=		${WRKDIR}/pkg-plist
CONFLICTS=	vnc-[0-9]* tightvnc-[0-9]*

MAN1=		vncviewer.1 \
		vncpasswd.1 \
		vncconfig.1 \
		x0vncserver.1

.if !defined(WITHOUT_SERVER)
MAN1+=		Xvnc.1 \
		vncserver.1
.endif

.include <bsd.port.pre.mk>

# No direct URL for VNC -- have to pseudo-submit their webform.
pre-fetch:
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && cd ${DISTDIR}/${DIST_SUBDIR} && \
	${FETCH_CMD} -o ${DISTNAME}.tar.gz 'http://www.realvnc.com/cgi-bin/download.cgi?product=free4/src/unix&acceptLicense=1&filever=4.1.1&filetype=tar_gz&haveDetails=1'
.if !defined(WITHOUT_SERVER)
	@${ECHO_MSG} ""
	@${ECHO_MSG} " ######################################################"
	@${ECHO_MSG} " # Use 'make -DWITHOUT_SERVER ...' if you do not wish #"
	@${ECHO_MSG} " # to compile/install the VNC server components.      #"
	@${ECHO_MSG} " ######################################################"
	@${ECHO_MSG} ""
.endif

post-extract:
.if !defined(WITHOUT_SERVER)
	@cd ${WRKSRC} && ${TAR} -cf - -C ${WRKDIR} xc | ${TAR} -xf - && \
	${RM} -rf ${WRKDIR}/xc
.endif

post-patch:
.if !defined(WITHOUT_SERVER)
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/xc/config/cf/vnc.def
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g' -e 's|%%CXX%%|${CXX}|g' \
		${WRKSRC}/xc/config/cf/FreeBSD.cf
.endif

post-build:
.if defined(WITHOUT_SERVER)
	@${ECHO_MSG} "Skipping build of VNC server."
.else
	cd ${WRKSRC}/xc && make CC=${CC} CXX=${CXX} World
.endif

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} -f ${PLIST}
	@${ECHO_CMD} bin/vncviewer >> ${PLIST}
	@${ECHO_CMD} bin/vncpasswd >> ${PLIST}
	@${ECHO_CMD} bin/vncconfig >> ${PLIST}
	@${ECHO_CMD} bin/x0vncserver >> ${PLIST}
.if !defined(WITHOUT_SERVER)
	@${ECHO_CMD} bin/Xvnc >> ${PLIST}
	@${ECHO_CMD} bin/vncserver >> ${PLIST}
	@${ECHO_CMD} share/vnc/classes/index.vnc >> ${PLIST}
	@${ECHO_CMD} share/vnc/classes/logo150x150.gif >> ${PLIST}
	@${ECHO_CMD} share/vnc/classes/vncviewer.jar >> ${PLIST}
	@${ECHO_CMD} @dirrm share/vnc/classes >> ${PLIST}
	@${ECHO_CMD} @dirrm share/vnc >> ${PLIST}
	@if [ -f ${WRKSRC}/xc/programs/Xserver/vnc/module/vnc.so ]; then \
		${ECHO_CMD} @cwd ${X11BASE} >> ${PLIST} ; \
		${ECHO_CMD} lib/modules/extensions/vnc.so >> ${PLIST} ; \
	fi
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${INSTALL_PROGRAM} ${WRKSRC}/vncconfig/vncconfig ${PREFIX}/bin/vncconfig
	${INSTALL_PROGRAM} ${WRKSRC}/x0vncserver/x0vncserver \
		${PREFIX}/bin/x0vncserver
	${INSTALL_MAN} ${WRKSRC}/vncviewer/vncviewer.man \
		${PREFIX}/man/man1/vncviewer.1
	${INSTALL_MAN} ${WRKSRC}/vncpasswd/vncpasswd.man \
		${PREFIX}/man/man1/vncpasswd.1
	${INSTALL_MAN} ${WRKSRC}/vncconfig/vncconfig.man \
		${PREFIX}/man/man1/vncconfig.1
	${INSTALL_MAN} ${WRKSRC}/x0vncserver/x0vncserver.man \
		${PREFIX}/man/man1/x0vncserver.1
.if !defined(WITHOUT_SERVER)
	@${REINPLACE_CMD} -e \
		's|/usr/local/vnc/classes|${PREFIX}/share/vnc/classes|g' \
		${WRKSRC}/vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/xc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver ${PREFIX}/bin/vncserver
	@if [ -f ${WRKSRC}/xc/programs/Xserver/vnc/module/vnc.so ]; then \
		${MKDIR} ${X11BASE}/lib/modules/extensions; \
		${INSTALL_DATA} ${WRKSRC}/xc/programs/Xserver/vnc/module/vnc.so ${X11BASE}/lib/modules/extensions; \
	fi
	${INSTALL_MAN} ${WRKSRC}/xc/programs/Xserver/Xvnc.man \
		${PREFIX}/man/man1/Xvnc.1
	${INSTALL_MAN} ${WRKSRC}/vncserver.man ${PREFIX}/man/man1/vncserver.1
	${MKDIR} ${PREFIX}/share/vnc/classes
	${CP} ${WRKDIR}/${DISTNAME}/common/javabin/* ${PREFIX}/share/vnc/classes
.endif

.include <bsd.port.post.mk>
