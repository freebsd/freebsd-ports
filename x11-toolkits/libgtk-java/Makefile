# New ports collection makefile for:   libgtk-java
# Date created:        22 December 2003
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgtk-java
PORTVERSION=	2.6.2
CATEGORIES=	x11-toolkits java
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.6
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Java wrapper for Gtk+, Pango, Atk, and Glib

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
USE_JAVA=	yes
JAVA_VERSION=	1.2+
JAVA_OS=	native
USE_GCC=	3.4
USE_GNOME=	gnomehack gtk20
CONFIGURE_ARGS=	--without-gcj-compile
CONFIGURE_ENV=	CPPFLAGS="-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd"
GTK_API_VERSION=	2.6
PLIST_SUB=		GTK_API_VERSION=${GTK_API_VERSION} PORTNAME=${PORTNAME}
PKGMESSAGE=		${WRKDIR}/pkg-message

do-install:
	${MKDIR} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/.libs/libgtkjni-${GTK_API_VERSION}.so \
		${PREFIX}/lib/libgtkjni-${GTK_API_VERSION}.so.1
	${LN} -sf ${PREFIX}/lib/libgtkjni-${GTK_API_VERSION}.so.1 \
		${PREFIX}/lib/libgtkjni-${GTK_API_VERSION}.so
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/gtk2-java.pc	${PREFIX}/libdata/pkgconfig
	${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/jni/jg_jnu.h ${PREFIX}/include/${PORTNAME}
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/gtk${GTK_API_VERSION}.jar ${JAVAJARDIR}
	${MKDIR} ${PREFIX}/share/${PORTNAME}/macros
	${INSTALL_DATA} ${WRKSRC}/macros/* ${PREFIX}/share/${PORTNAME}/macros

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/THANKS ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/api
	cd ${WRKSRC}/doc/api && ${FIND} . | ${CPIO} -pdmu ${DOCSDIR}/api
	${MKDIR} ${DOCSDIR}/examples
	cd ${WRKSRC}/doc/examples && ${FIND} . \
		| ${CPIO} -pdmu ${DOCSDIR}/examples
.endif
	@${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%GTK_API_VERSION%%|${GTK_API_VERSION}|g' \
		 < ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
