# New ports collection makefile for:	vnc
# Date created:		24 February 1998
# Whom:			msmith
#
# $FreeBSD$
#

PORTNAME=	vnc
PORTVERSION=	4.1.3
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.realvnc.com/:vnc
DISTNAME=	vnc-4_1_3-unixsrc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:vnc
DIST_SUBDIR=	xc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display X and Win32 desktops on remote X/Win32/Java displays

RUN_DEPENDS=	xorg-fonts>=7.2:${PORTSDIR}/x11-fonts/xorg-fonts \
		xauth:${PORTSDIR}/x11/xauth

GNU_CONFIGURE=	yes
# The vnc supplied zlib seg. faults if compiled with -O
CONFIGURE_ARGS=	--with-installed-zlib
USE_XORG=	x11 xext xpm xext xtst sm ice inputproto
WANT_PERL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
PLIST=		${WRKDIR}/pkg-plist
CONFLICTS=	tightvnc-[0-9]* tridiavnc-[0-9]*

OPTIONS=	SERVER "Install VNC server components" on

MAN1=		vncviewer.1 \
		vncpasswd.1 \
		vncconfig.1 \
		x0vncserver.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SERVER)
# This is a placeholder MASTER_SITES entry -- see the pre-fetch target.
MASTER_SITES+=	${MASTER_SITE_XFREE:S/$/:x/}
MASTER_SITE_SUBDIR+=	4.3.0/:x
DISTFILES+=	X430src-1.tgz:x \
		X430src-2.tgz:x \
		X430src-3.tgz:x

RUN_DEPENDS+=	xauth:${PORTSDIR}/x11/xauth \
		${LOCALBASE}/lib/X11/fonts/misc/6x13-ISO8859-1.pcf.gz:${X_FONTS_MISC_PORT} \
		${X11BASE}/lib/X11/fonts/misc/fonts.alias:${X_FONTS_ALIAS_PORT}

USE_PERL5=	yes

EXTRA_PATCHES+=	${WRKSRC}/xc.patch \
		${PATCHDIR}/vnc.def-patch \
		${PATCHDIR}/FreeBSD.cf-patch \
		${PATCHDIR}/extra-patch-xfree86 \
		${PATCHDIR}/extra-patch-fix_Xvnc_no_valid_address \
		${PATCHDIR}/extra-patch-xc-config-util-printver.c

MAN1+=		Xvnc.1 \
		vncserver.1

PLIST_SUB+=	SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "
.endif

# No direct URL for VNC -- have to pseudo-submit their webform.
pre-fetch:
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && cd ${DISTDIR}/${DIST_SUBDIR} && \
	${FETCH_CMD} -o ${DISTNAME}.tar.gz 'http://www.realvnc.com/cgi-bin/download.cgi?product=free4/src/unix&acceptLicense=1&haveDetails=1&filetype=tar_gz&filever=${PORTVERSION}'

post-extract:
.if !defined(WITHOUT_SERVER)
	@cd ${WRKSRC} && ${TAR} -cf - -C ${WRKDIR} xc | ${TAR} -xf - && \
	${RM} -rf ${WRKDIR}/xc
.endif

post-patch:
.if !defined(WITHOUT_SERVER)
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/xc/config/cf/vnc.def
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g' -e 's|%%CXX%%|${CXX}|g' \
		-e 's|%%CFLAGS%%|${CFLAGS}|g' \
		${WRKSRC}/xc/config/cf/FreeBSD.cf
.endif

post-build:
.if defined(WITHOUT_SERVER)
	@${ECHO_MSG} "Skipping build of VNC server."
.else
	cd ${WRKSRC}/xc && make CC=${CC} CXX=${CXX} World
.endif

pre-install:
	@${CP} ${PKGDIR}/pkg-plist ${PLIST}
.if !defined(WITHOUT_SERVER)
	@if [ -f ${WRKSRC}/xc/programs/Xserver/vnc/module/vnc.so ]; then \
		${ECHO_CMD} lib/modules/extensions/vnc.so ; \
		${ECHO_CMD} "@dirrmtry lib/modules/extensions" ; \
		${ECHO_CMD} "@dirrmtry lib/modules" ; \
		${ECHO_CMD} "@dirrmtry lib" ; \
	fi >> ${PLIST}
.endif

do-install:
.for f in vncviewer vncpasswd vncconfig x0vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/${f}/${f} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}/${f}.man ${PREFIX}/man/man1/${f}.1
.endfor
.if !defined(WITHOUT_SERVER)
	@${REINPLACE_CMD} -e \
		's|/usr/local/vnc/classes|${DATADIR}/classes|g' \
		${WRKSRC}/vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/xc/programs/Xserver/Xvnc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver ${PREFIX}/bin
	@if [ -f ${WRKSRC}/xc/programs/Xserver/vnc/module/vnc.so ]; then \
		${MKDIR} ${LOCALBASE}/lib/modules/extensions ; \
		${INSTALL_PROGRAM} \
			${WRKSRC}/xc/programs/Xserver/vnc/module/vnc.so \
			${LOCALBASE}/lib/modules/extensions ; \
	fi
	${INSTALL_MAN} ${WRKSRC}/xc/programs/Xserver/Xvnc.man \
		${PREFIX}/man/man1/Xvnc.1
	${INSTALL_MAN} ${WRKSRC}/vncserver.man ${PREFIX}/man/man1/vncserver.1
	${MKDIR} ${DATADIR}/classes
	${INSTALL_DATA} ${WRKSRC}/../common/javabin/* ${DATADIR}/classes
.endif

.include <bsd.port.post.mk>
