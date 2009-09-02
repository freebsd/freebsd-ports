# New ports collection makefile for:	rssowl
# Date created:				February, 1st 2006
# Whom:					Matthias Sund <m.sund@arcor.de>
#
# $FreeBSD$
#

PORTNAME=	rssowl
PORTVERSION=	1.2.3
PORTREVISION=	5
CATEGORIES=	www java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20classic%20%28dont%20use%29/${PORTVERSION}
DISTNAME=	rssowl_${PORTVERSION:S|.|_|g}_src

MAINTAINER=	m.sund@arcor.de
COMMENT=	Portable RSS, RDF, Atom Newsfeeds reader

BUILD_DEPENDS=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt
RUN_DEPENDS=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt

BUILD_WRKSRC=	${WRKSRC}/src

ONLY_FOR_ARCHS=	i386 amd64

USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native
JAVA_RUN=	yes

USE_ANT=	yes
ALL_TARGET=	deploy_linux

DOCS_PREFIX=	doc

PORTDOCS=	CHANGELOG.txt epl-v10.html mpl-v11.txt LICENSE.txt \
		faq.html rssowl_i18n.template README.txt faq.xml

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
		 s|$${root}/lib/swt\.jar|${JAVALIBDIR}/swt.jar|; \
		 s|3230|3235|' \
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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${DOCS_PREFIX}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
