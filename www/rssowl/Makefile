# New ports collection makefile for:	rssowl
# Date created:				February, 1st 2006
# Whom:					Matthias Sund <m.sund@arcor.de>
#
# $FreeBSD$
#

PORTNAME=	rssowl
PORTVERSION=	1.1.3
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	rssowl
DISTNAME=	rssowl_${PORTVERSION:S|.|_|g}_src

MAINTAINER=	m.sund@arcor.de
COMMENT=	Portable RSS, RDF, Atom Newsfeeds reader

BUILD_DEPENDS=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt31
RUN_DEPENDS=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt31

USE_X_PREFIX=	yes
BUILD_WRKSRC=	${WRKSRC}/src

ONLY_FOR_ARCHS=	i386 amd64

USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native
JAVA_RUN=	yes

USE_ANT=	yes
ALL_TARGET=	deploy_linux

PLIST_FILES=	bin/rssowl %%DATADIR%%/rssowl.jar share/pixmaps/rssowl.png
PLIST_DIRS=	%%DATADIR%%

DESKTOP_ENTRIES="RSSOwl" \
		"Read newsfeeds" \
		"rssowl.png" \
		"rssowl" \
		"Application;Network;News;" \
		true

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${java\.io\.tmpdir}/source/|$${basedir}/temp/|; \
		 s|$${root}/lib/swt\.jar|${JAVALIBDIR}/swt.jar|' \
		${BUILD_WRKSRC}/build.xml

post-build:
	@${ECHO_CMD} '#!/bin/sh' > ${WRKSRC}/rssowl
	@${ECHO_CMD} "exec java -jar ${DATADIR}/rssowl.jar" >> ${WRKSRC}/rssowl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rssowl ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/rssowl.jar ${DATADIR}
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/img/32x32.png ${PREFIX}/share/pixmaps/rssowl.png

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
