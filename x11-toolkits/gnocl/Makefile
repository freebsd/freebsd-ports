# New ports collection makefile for:	gnocl
# Date created:         15 August 2003
# Whom:                 Stephane Legrand <stephane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnocl
PORTVERSION=	0.9.94
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	SF/gnocl
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	GTK+ and Gnome extension for Tcl

USE_GMAKE=	yes
USE_ZIP=	yes
USE_GNOME=	gtk20 libglade2 gtksourceview2 gtkhtml3
USE_TCL=	84
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src
CFLAGS+=	-I${LOCALBASE}/include/tcl8.4

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CFLAGS+=	-fPIC
.endif

GNOCL_CANVAS_FILE="lib/libgnoclCanvas.so.1"
GNOCL_GCONF_FILE="lib/libgnoclGconf.so.1"
GNOCL_GNOME_FILE="lib/libgnoclGnome.so.1"
GNOCL_VFS_FILE="lib/libgnoclVFS.so.1"

.if defined(WITHOUT_CANVAS)
GNOCL_CANVAS_FILE=	"@comment "
.else
USE_GNOME+=	libgnomecanvas
.endif

.if defined(WITHOUT_GNOME)
GNOCL_GNOME_FILE=	"@comment "
.else
USE_GNOME+=	libgnomeui gnomepanel
.endif

.if defined(WITHOUT_GNOMEVFS2)
GNOCL_VFS_FILE=		"@comment "
.else
USE_GNOME+=	gnomevfs2
.endif

PLIST_SUB+=	GNOCL_CANVAS_FILE=${GNOCL_CANVAS_FILE}
PLIST_SUB+=	GNOCL_GCONF_FILE=${GNOCL_GCONF_FILE}
PLIST_SUB+=	GNOCL_GNOME_FILE=${GNOCL_GNOME_FILE}
PLIST_SUB+=	GNOCL_VFS_FILE=${GNOCL_VFS_FILE}

post-extract:
	${FIND} ${WRKSRC} -name "*.o" -delete
	${RMDIR} ${WRKSRC}/doc/html		# Remove empty/stale directory

post-patch:
.if !defined(WITHOUT_CANVAS)
	${REINPLACE_CMD} -e 's=^#USE_CANVAS=USE_CANVAS=' ${BUILD_WRKSRC}/Makefile
.endif
.if !defined(WITHOUT_GCONF)
	${REINPLACE_CMD} -e 's=^#USE_GCONF=USE_GCONF=' ${BUILD_WRKSRC}/Makefile
.endif
.if !defined(WITHOUT_GNOME)
	${REINPLACE_CMD} -e 's=^#USE_GNOME=USE_GNOME=' ${BUILD_WRKSRC}/Makefile
.endif
.if !defined(WITHOUT_GNOMEVFS2)
	${REINPLACE_CMD} -e 's=^#USE_VFS=USE_VFS=' ${BUILD_WRKSRC}/Makefile
.endif
	${FIND} ${WRKSRC}/demos -name "*.tcl" | ${XARGS} \
		${REINPLACE_CMD} -i "" -e 's|tclsh|${TCLSH}|g; \
		s|package require Gnocl|load ${PREFIX}/lib/libgnocl.so.1; package require Gnocl|g; \
		s|package require GnoclCanvas|load ${PREFIX}/lib/libgnoclCanvas.so.1; package require GnoclCanvas|g; \
		s|package require GnoclGconf|load ${PREFIX}/lib/libgnoclGconf.so.1; package require GnoclGconf|g; \
		s|package require GnoclGnome|load ${PREFIX}/lib/libgnoclGnome.so.1; package require GnoclGnome|g; \
		s|package require GnoclVFS|load ${PREFIX}/lib/libgnoclVFS.so.1; package require GnoclVFS|g'

do-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/gnocl.so ${PREFIX}/lib/libgnocl.so.1
	if ${TEST} -f ${BUILD_WRKSRC}/gnoclCanvas.so; then \
		${INSTALL_DATA} ${BUILD_WRKSRC}/gnoclCanvas.so ${PREFIX}/lib/libgnoclCanvas.so.1; \
	fi; \
	if ${TEST} -f ${BUILD_WRKSRC}/gnoclGconf.so; then \
		${INSTALL_DATA} ${BUILD_WRKSRC}/gnoclGconf.so ${PREFIX}/lib/libgnoclGconf.so.1; \
	fi; \
	if ${TEST} -f ${BUILD_WRKSRC}/gnoclGnome.so; then \
		${INSTALL_DATA} ${BUILD_WRKSRC}/gnoclGnome.so ${PREFIX}/lib/libgnoclGnome.so.1; \
	fi; \
	if ${TEST} -f ${BUILD_WRKSRC}/gnoclVFS.so; then \
		${INSTALL_DATA} ${BUILD_WRKSRC}/gnoclVFS.so ${PREFIX}/lib/libgnoclVFS.so.1; \
	fi; \

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	${INSTALL} -d ${EXAMPLESDIR}
	(cd ${WRKSRC}/demos && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
