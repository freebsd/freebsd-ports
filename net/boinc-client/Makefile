# New ports collection makefile for:	boinc
# Date created:				01 October 2004
# Whom:					J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	boinc-client
PORTVERSION=	5.8.11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.oook.cz/bsd/distfiles/
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

OPTIONS=	X11 "Build Boinc Manager GUI" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
USE_WX=		2.6+
WX_CONF_ARGS=	absolute
CPPFLAGS+=		-I${X11BASE}/include
.else
CONFIGURE_ARGS+=	--with-wx-config=false --without-x
.endif

.if !defined(WITHOUT_X11)
USE_ICONV=	yes
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg \
		glut:${PORTSDIR}/graphics/libglut
.endif

.if !defined(WITHOUT_X11)
PLIST_SUB+=	BOINC_GUI=""
.else
PLIST_SUB+=	BOINC_GUI="@comment "
.endif

.if ${OSVERSION} < 500000
BROKEN=		Does not compile. Consider upgrading your FreeBSD to at least 5.X
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gui_rpc_auth.cfg|${BOINC_HOME}/gui_rpc_auth.cfg|g' \
		${WRKSRC}/client/file_names.h ${WRKSRC}/lib/boinc_cmd.C \
		${WRKSRC}/clientgui/MainDocument.cpp
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' ${WRKSRC}/clientgui/stdwx.h

# kill -O3 from clientgui build, it triggers some optimization bug and segfaults on runtime with -O3
post-configure:
	@${REINPLACE_CMD} -e 's|-O3 ||' ${WRKSRC}/clientgui/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/version.h ${PREFIX}/include/BOINC
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
