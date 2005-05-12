# New ports collection makefile for:   boinc
# Date created:        01 October 2004
# Whom:                J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	boinc-client
PORTVERSION=	4.67.20050320
CATEGORIES=	net
MASTER_SITES=	http://boinc.berkeley.edu/source/nightly/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DISTNAME=	boinc-cvs-2005-03-20

MAINTAINER=	fbsd@opal.com
COMMENT=	Berkeley Open Infrastructure for Network Computing client

.include <bsd.port.pre.mk>

# Build with "make -DWITHOUT_X11" if you don't want the boincmgr
# GUI management interface or the "screensaver" status displays
# from any of the client applications.
#
# Defining WITHOUT_X11 removes the dependencies on the X11 libs
# and the wxgtk2 toolkit and jpeg graphics lib.

.if !defined(WITHOUT_X11)
LIB_DEPENDS+=	iconv:${PORTSDIR}/converters/libiconv \
		wx_gtk2:${PORTSDIR}/x11-toolkits/wxgtk24 \
		jpeg:${PORTSDIR}/graphics/jpeg \
		glut:${PORTSDIR}/graphics/libglut
USE_XLIBS=	yes
.endif

USE_AUTOMAKE_VER=	19
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_LIBTOOL_VER=	15

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-server
.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--with-wx-config=false
.endif
CONFIGURE_ENV=	CPPFLAGS=-I${X11BASE}/include CXXFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include"

WRKSRC=		${WRKDIR}/boinc
PKGINSTALL=	${WRKDIR}/pkg-install
PKGPLIST=	${WRKDIR}/pkg-plist

MAN1=		boinc.1
.if !defined(WITHOUT_X11)
MLINKS=		boinc.1 boincmgr.1
.endif

FIND_BOINC_BINARY=(cd ${WRKSRC}/client; make -V CLIENT_BIN_FILENAME)
FIND_BOINCMGR_BINARY=(cd ${WRKSRC}/client; make -V CLIENT_GUI_BIN_FILENAME)
BOINC_BINARY=	boinc-client

BOINC_USER=	boinc
BOINC_GROUP=	nobody
BOINC_HOME=	/var/db/boinc

.if ${OSVERSION} < 500000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clientgui-MainDocument.cpp
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clientgui-MainFrame.cpp
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clientgui-ViewProjects.cpp
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clientgui-ViewResources.cpp
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clientgui-ViewTransfers.cpp
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clientgui-ViewWork.cpp
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clientgui-stdwx.h
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-lib-acct_mgr_client.C
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-lib-network.h
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-lib-gui_rpc_client.C
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-lib-parse.C
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-zip-boinc_zip.cpp
.endif

pre-configure:
	cd ${WRKSRC}; ${ACLOCAL} -I ${LOCALBASE}/share/libtool${USE_LIBTOOL_VER}/libltdl -I m4

post-build:
	${SED}  -e "s:%%BOINC_BINARY%%:${BOINC_BINARY}:g" \
		-e "s:%%BOINC_HOME%%:${BOINC_HOME}:g" \
		-e "s:%%BOINC_USER%%:${BOINC_USER}:g" \
		-e "s:%%BOINC_GROUP%%:${BOINC_GROUP}:g" \
		-e "s:%%LOCALBASE%%:${LOCALBASE}:g" \
		< ${FILESDIR}/boinc.sh > ${WRKDIR}/boinc.sh
	${SED}  -e "s:%%BOINC_BINARY%%:${BOINC_BINARY}:g" \
		-e "s:%%BOINC_HOME%%:${BOINC_HOME}:g" \
		-e "s:%%BOINC_USER%%:${BOINC_USER}:g" \
		-e "s:%%BOINC_GROUP%%:${BOINC_GROUP}:g" \
		-e "s:%%LOCALBASE%%:${LOCALBASE}:g" \
		< ${FILESDIR}/boinc.1 > ${WRKDIR}/boinc.1
	${SED}  -e "s:%%BOINC_BINARY%%:${BOINC_BINARY}:g" \
		-e "s:%%BOINC_HOME%%:${BOINC_HOME}:g" \
		-e "s:%%BOINC_USER%%:${BOINC_USER}:g" \
		-e "s:%%BOINC_GROUP%%:${BOINC_GROUP}:g" \
		-e "s:%%LOCALBASE%%:${LOCALBASE}:g" \
		< ${PKGDIR}/pkg-install > ${WRKDIR}/pkg-install
	${SED}  -e "s:%%BOINC_BINARY%%:${BOINC_BINARY}:g" \
		-e "s:%%BOINC_HOME%%:${BOINC_HOME}:g" \
		-e "s:%%BOINC_USER%%:${BOINC_USER}:g" \
		-e "s:%%BOINC_GROUP%%:${BOINC_GROUP}:g" \
		-e "s:%%LOCALBASE%%:${LOCALBASE}:g" \
		< ${FILESDIR}/rc-boinc.sh > ${WRKDIR}/rc-boinc.sh

do-install:
	${MKDIR} ${PREFIX}/lib/boinc
	${INSTALL_PROGRAM} ${WRKSRC}/client/`${FIND_BOINC_BINARY}` ${PREFIX}/lib/boinc/${BOINC_BINARY}
.if !defined(WITHOUT_X11)
	${INSTALL_PROGRAM} ${WRKSRC}/clientgui/`${FIND_BOINCMGR_BINARY}` ${PREFIX}/bin
.endif
	${MKDIR} ${PREFIX}/include/BOINC
	${INSTALL} ${WRKSRC}/api/*.h ${PREFIX}/include/BOINC
	${INSTALL} ${WRKSRC}/lib/*.h ${PREFIX}/include/BOINC
	${INSTALL} ${WRKSRC}/zip/*.h ${PREFIX}/include/BOINC
	${INSTALL} ${WRKSRC}/api/*.a ${PREFIX}/lib
	${INSTALL} ${WRKSRC}/lib/*.a ${PREFIX}/lib
	${INSTALL} ${WRKSRC}/zip/*.a ${PREFIX}/lib
	${INSTALL} ${WRKSRC}/RSAEuro/source/librsaeuro.a ${PREFIX}/lib

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/boinc.sh ${PREFIX}/bin/boinc
	${INSTALL_MAN} ${WRKDIR}/boinc.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKDIR}/rc-boinc.sh ${PREFIX}/etc/rc.d/boinc.sh
	${REINPLACE_CMD} \
	    -e "s:%%BOINC_BINARY%%:${BOINC_BINARY}:g" \
	    -e "s:%%BOINC_HOME%%:${BOINC_HOME}:g" \
	    -e "s:%%BOINC_USER%%:${BOINC_USER}:g" \
	    ${TMPPLIST}
	${CAT} ${PKGMESSAGE}
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
