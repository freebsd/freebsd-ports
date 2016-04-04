# Created by: Matthias Sund <m.sund@arcor.de>
# $FreeBSD$

PORTNAME=	rssowl
PORTVERSION=	1.2.3
PORTREVISION=	10
CATEGORIES=	www java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20classic%20%28dont%20use%29/${PORTVERSION}
DISTNAME=	rssowl_${PORTVERSION:S|.|_|g}_src

MAINTAINER=	m.sund@arcor.de
COMMENT=	Portable RSS, RDF, Atom Newsfeeds reader

BUILD_DEPENDS=	${JAVALIBDIR}/swt.jar:x11-toolkits/swt
RUN_DEPENDS=	${JAVALIBDIR}/swt.jar:x11-toolkits/swt

BUILD_WRKSRC=	${WRKSRC}/src

ONLY_FOR_ARCHS=	i386 amd64

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
JAVA_RUN=	yes

USE_ANT=	yes
ALL_TARGET=	deploy_linux

DOCS_PREFIX=	doc

PORTDOCS=	CHANGELOG.txt epl-v10.html mpl-v11.txt LICENSE.txt \
		faq.html rssowl_i18n.template README.txt faq.xml

PLIST_FILES=	bin/rssowl %%DATADIR%%/rssowl.jar share/pixmaps/rssowl.png
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="RSSOwl" \
		"Newsfeeds reader" \
		"${PREFIX}/share/pixmaps/rssowl.png" \
		"rssowl" \
		"Network;News;Java;" \
		true

.include <bsd.port.options.mk>

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
	${INSTALL_SCRIPT} ${WRKSRC}/rssowl ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/rssowl.jar ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/img/32x32.png ${STAGEDIR}${PREFIX}/share/pixmaps/rssowl.png
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${DOCS_PREFIX}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
