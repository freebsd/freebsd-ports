# New ports collection makefile for:	boinc
# Date created:				01 October 2004
# Whom:					J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	boinc-client
PORTVERSION=	6.4.5
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Berkeley Open Infrastructure for Network Computing client

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

BOINC_USER?=	boinc
BOINC_GROUP?=	nobody
BOINC_HOME?=	/var/db/boinc

PLIST_SUB=	BOINC_HOME="${BOINC_HOME}" BOINC_USER="${BOINC_USER}" BOINC_GROUP="${BOINC_GROUP}"

SUB_FILES=	pkg-install
SUB_LIST=	BOINC_HOME="${BOINC_HOME}" BOINC_USER="${BOINC_USER}" BOINC_GROUP="${BOINC_GROUP}"

USE_RC_SUBR=	boinc.sh

CONFIGURE_ARGS=	--disable-server
CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS:=	${CXXFLAGS:N-O*:N-f*} -O3
CFLAGS:=	${CFLAGS:N-O*:N-f*} -O3
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" CXXFLAGSS="${CXXFLAGS}" CFLAGS="${CFLAGS}"

OPTIONS=	X11 "Build Boinc Manager GUI" on \
		ALT "Accept Linux science applications" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)
USE_GL=		glut
USE_XORG=	x11
USE_WX=		2.6+
WX_CONF_ARGS=	absolute
CPPFLAGS+=		-I${LOCALBASE}/include

USE_ICONV=	yes
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg

PLIST_SUB+=	BOINC_GUI=""
.else
CONFIGURE_ARGS+=	--with-wx-config=false --without-x
PLIST_SUB+=	BOINC_GUI="@comment "
.endif

.if defined(WITH_ALT)
CONFIGURE_ARGS+=--with-boinc-alt-platform=i686-pc-linux-gnu
USE_LINUX=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gui_rpc_auth.cfg|${BOINC_HOME}/gui_rpc_auth.cfg|g' \
		${WRKSRC}/client/file_names.h ${WRKSRC}/lib/boinc_cmd.cpp \
		${WRKSRC}/clientgui/MainDocument.cpp
	@${REINPLACE_CMD} -e 's|../curl/ca-bundle.crt||' ${WRKSRC}/client/Makefile.in
	@${REINPLACE_CMD} -e 's|ca-bundle.crt|${LOCALBASE}/share/certs/ca-root-nss.crt|' ${WRKSRC}/client/file_names.h
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' ${WRKSRC}/clientgui/stdwx.h
	@${REINPLACE_CMD} -e 's| install-dist_pkgdataDATA||' ${WRKSRC}/clientgui/res/Makefile.in
	@${REINPLACE_CMD} -e 's|boincmgr.16x16.png boincmgr.32x32.png boincmgr.48x48.png||' ${WRKSRC}/clientgui/res/Makefile.in
	@${REINPLACE_CMD} -e 's|client/scripts||' ${WRKSRC}/Makefile.in

# kill -O3 from clientgui build, it triggers some optimization bug and segfaults on runtime with -O3
post-configure:
	@${REINPLACE_CMD} -e 's|-O3 ||' ${WRKSRC}/clientgui/Makefile

post-install:
.for file in boinc_gl graphics_api graphics_data reduce
	${INSTALL_DATA} ${WRKSRC}/api/${file}.h ${PREFIX}/include/boinc/
.endfor
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
