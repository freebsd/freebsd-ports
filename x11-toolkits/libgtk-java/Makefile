# New ports collection makefile for:   libgtk-java
# Date created:        22 December 2003
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/libgtk-java/Makefile,v 1.16 2005/10/29 22:06:06 marcus Exp $
#

PORTNAME=	libgtk-java
PORTVERSION=	2.10.2
PORTREVISION=	3
CATEGORIES=	x11-toolkits java
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Java wrapper for Gtk+, Pango, Atk, and Glib

LIB_DEPENDS=	cairojni-${CAIRO_API_VERSION}.1:${PORTSDIR}/graphics/cairo-java

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.2+
JAVA_OS=	native
USE_GNOME=	gnomehack gtk20
CONFIGURE_ARGS=	--without-gcj-compile --with-jardir=${JAVAJARDIR} \
		--without-javadocs # needs docbook-utils
NOPORTDOCS=	yes # needs docbook-utils and some parts are broken.
CONFIGURE_ENV=	CPPFLAGS="-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd"
GTK_API_VERSION=	2.10
CAIRO_API_VERSION=	1.0
PLIST_SUB=		GTK_API_VERSION=${GTK_API_VERSION} PORTNAME=${PORTNAME}
PKGMESSAGE=		${WRKDIR}/pkg-message

# jikes related
CONFIGURE_ENV+=	BOOTCLASSPATH=${JAVA_CLASSES}
MAKE_ENV+=	BOOTCLASSPATH=${JAVA_CLASSES}

post-patch:
	@${REINPLACE_CMD} -e 's|sed -i|${SED} -i.bak -e|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|||' ${WRKSRC}/gtk2-java.pc.in
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
		${WRKSRC}/configure

do-install:
	${MKDIR} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/.libs/libgtkjni-${GTK_API_VERSION}.so \
		${PREFIX}/lib/libgtkjni-${GTK_API_VERSION}.so.1
	${LN} -sf ${PREFIX}/lib/libgtkjni-${GTK_API_VERSION}.so.1 \
		${PREFIX}/lib/libgtkjni-${GTK_API_VERSION}.so
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/gtk2-java.pc	${PREFIX}/libdata/pkgconfig
	${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/jni/gtk_java.h \
		${PREFIX}/include/${PORTNAME}
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
	${TOUCH} ${DOCSDIR}/api/packages.html
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
