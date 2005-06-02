# New ports collection makefile for:   boinc
# Date created:        01 October 2004
# Whom:                J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	boinc-client
PORTVERSION=	4.68.20050601
CATEGORIES=	net
MASTER_SITES=	http://boinc.berkeley.edu/source/nightly/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DISTNAME=	boinc-cvs-2005-06-01

MAINTAINER=	fbsd@opal.com
COMMENT=	Berkeley Open Infrastructure for Network Computing client

.include <bsd.port.pre.mk>

# Disable GUI on FreeBSD 4.x due to problems with wxgtk lib
.if ${OSVERSION} < 500000
WITHOUT_X11=	yes
.endif

.if !defined(WITHOUT_X11)
LIB_DEPENDS+=	iconv:${PORTSDIR}/converters/libiconv \
		wx_base:${PORTSDIR}/x11-toolkits/wxgtk26 \
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

MAN1=		boinc.1
.if !defined(WITHOUT_X11)
MLINKS=		boinc.1 boincmgr.1
.endif

BOINC_USER=	boinc
BOINC_GROUP=	nobody
BOINC_HOME=	/var/db/boinc
BOINC_BINARY=	boinc-client

PLIST_SUB=	BOINC_BINARY="${BOINC_BINARY}" BOINC_HOME="${BOINC_HOME}" \
		BOINC_USER="${BOINC_USER}" BOINC_GROUP="${BOINC_GROUP}"
.if !defined(WITHOUT_X11)
PLIST_SUB+=	GUI=""
.else
PLIST_SUB+=	GUI="@comment "
.endif

SUB_FILES=	bin-boinc.sh boinc.1 boinc.sh pkg-install
SUB_LIST=	BOINC_BINARY="${BOINC_BINARY}" BOINC_HOME="${BOINC_HOME}" \
		BOINC_USER="${BOINC_USER}" BOINC_GROUP="${BOINC_GROUP}"

USE_RC_SUBR=	boinc.sh

CONFIGURE_ARGS=	--disable-server
.if !defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--with-wx-config=wxgtk2-2.6-config
.else
CONFIGURE_ARGS+=	--with-wx-config=false
.endif
CONFIGURE_ENV=	CPPFLAGS=-I${X11BASE}/include CXXFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include"

FIND_BOINC_BINARY=(cd ${WRKSRC}/client; make -V CLIENT_BIN_FILENAME)
FIND_BOINCMGR_BINARY=(cd ${WRKSRC}/client; make -V CLIENT_GUI_BIN_FILENAME)

WRKSRC=		${WRKDIR}/boinc
PKGINSTALL=	${WRKDIR}/pkg-install
PKGPLIST=	${WRKDIR}/pkg-plist

.if ${OSVERSION} < 500000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-client-time_stats.C
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clientgui-MainDocument.cpp
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clientgui-MainFrame.cpp
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clientgui-ViewProjects.cpp
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clientgui-ViewResources.cpp
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clientgui-ViewTransfers.cpp
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clientgui-ViewWork.cpp
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clientgui-stdwx.h
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-lib-acct_mgr_client.C
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-lib-diagnostics.h
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-lib-gui_rpc_client.C
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-lib-parse.C
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-zip-boinc_zip.cpp
.endif

pre-configure:
	cd ${WRKSRC}; ${ACLOCAL} -I m4

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
	${INSTALL_SCRIPT} ${WRKDIR}/bin-boinc.sh ${PREFIX}/bin/boinc
	${INSTALL_MAN} ${WRKDIR}/boinc.1 ${PREFIX}/man/man1
	${CAT} ${PKGMESSAGE}

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
