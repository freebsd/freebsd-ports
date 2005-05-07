# New ports collection makefile for:   libgtk-java
# Date created:        22 December 2003
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgtk-java
PORTVERSION=	2.4.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits java
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.4
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Java wrapper for Gtk+, Pango, Atk, and Glib

BROKEN=		Does not build

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.2+
JAVA_OS=	native
USE_GNOME=	gnomehack gtk20
CONFIGURE_ARGS=	--without-gcj-compile \
		--with-java-prefix=${JAVA_HOME}
CONFIGURE_ENV=	DB2="/dev/null"

GTK_API_VERSION=	2.4
VERSION=		2.4.0
PLIST_SUB=		GTK_API_VERSION=${GTK_API_VERSION} \
			PORTVERSION=${VERSION}

PKGMESSAGE=		${WRKDIR}/pkg-message

do-install:
	${MKDIR} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/gtk/lib/libgtkjava${GTK_API_VERSION}.so.${VERSION} \
		${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libgtkjava${GTK_API_VERSION}.so.${VERSION} ${PREFIX}/lib/libgtkjava${GTK_API_VERSION}.so
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/gtk/lib/gtk${GTK_API_VERSION}-${VERSION}.jar \
		${JAVAJARDIR}
	${LN} -sf ${JAVAJARDIR}/gtk${GTK_API_VERSION}-${VERSION}.jar \
		${JAVAJARDIR}/gtk${GTK_API_VERSION}.jar

post-install:
	@${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%GTK_API_VERSION%%|${GTK_API_VERSION}|g' \
		 < ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
