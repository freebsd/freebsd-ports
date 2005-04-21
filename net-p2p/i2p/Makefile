# New ports collection makefile for:	i2p
# Date created:		Sun Jan  9 05:05:02 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	i2p
PORTVERSION=	0.5.0.7
CATEGORIES=	net java security
MASTER_SITES=	http://dev.i2p.net/i2p/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	An anonymous network

RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_BZIP2=	yes
USE_REINPLACE=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.4
JAVA_OS=	native
USE_ANT=	yes

ALL_TARGET=	\
		updater \
		tarball

.ifndef(NOPORTDOCS)
ALL_TARGET+=	javadoc
.endif

JAVADOC_WRKSRC=	${WRKSRC}/build/javadoc
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:S/./_/g}

DOC_FILES=	\
		readme.html \
		allclasses-frame.html \
		allclasses-noframe.html \
		constant-values.html \
		deprecated-list.html \
		help-doc.html \
		index.html \
		overview-frame.html \
		overview-summary.html \
		overview-tree.html \
		package-list \
		packages.html \
		serialized-form.html \
		stylesheet.css
DOC_DIRS=	\
		freenet/ \
		index-files/ \
		net/ \
		org/ \
		resources/
PORTDOCS=	${DOC_FILES} \
		${DOC_DIRS}

PLIST_DIRS=	\
		%%DATADIR%%
PLIST_FILES=	\
		sbin/i2prouter \
		%%DATADIR%%/i2p.tar.bz2 \
		%%DATADIR%%/i2pupdate.zip

post-patch:
	@${SED} \
		-e "s|%%DATADIR%%|${DATADIR}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh
# postinstall.sh SHOULD only do post installation house keeping
	@${REINPLACE_CMD} -E \
		-e 's|./i2prouter[[:space:]]+start||' \
		${WRKSRC}/installer/resources/postinstall.sh

do-install:
	@${MKDIR} ${DATADIR}
# install
	@${INSTALL_DATA} ${WRKSRC}/i2p.tar.bz2 \
		${DATADIR}/
# update
	@${INSTALL_DATA} ${WRKSRC}/i2pupdate.zip \
		${DATADIR}/
# wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
		${PREFIX}/sbin/i2prouter
# doc
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.html ${DOCSDIR}
.for doc in ${DOC_FILES}
	@if [ -f ${JAVADOC_WRKSRC}/${doc} ]; then \
		${INSTALL_DATA} ${JAVADOC_WRKSRC}/${doc} ${DOCSDIR} ; \
	fi
.endfor
# line taken from textproc/xerces-j maintained by hq@FreeBSD.org
	@cd ${JAVADOC_WRKSRC} && \
		${FIND} ${DOC_DIRS} -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} ${DOC_DIRS} -not -type d -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif

.include <bsd.port.mk>
