# New ports collection makefile for:	pdfmerge
# Date created:		Mar 15 2005
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	pdfmerge
PORTVERSION=	1.0
CATEGORIES=	print
MASTER_SITES=	http://web.hku.hk/cgi-bin/cgiwrap/kangsg/freeware/
DISTNAME=	PDFMerge
EXTRACT_SUFX=	.zip

MAINTAINER=	nivit@email.it
COMMENT=	A shell script (with simple UI) to merge PDF files

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_ZIP=	yes
USE_GHOSTSCRIPT_RUN=	yes

WRKSRC=		${WRKDIR}/Scripts
NO_BUILD=	yes
NO_INSTALL_MANPAGES=	yes

FIND_ARGS=	\! -type d -and \! -name "*.orig" \! -name "*.txt" \! -name "*.bak"
LINK_OPTS?=	-sf
SED_OPTS=	-i .bak

post-patch:
	@REPLACE_FILES=$$(${FIND} ${WRKSRC} ${FIND_ARGS} ); \
	for FILE in $${REPLACE_FILES}; do \
	    ${SED} ${SED_OPTS} \
	    -e "/%%LOCALBASE%%/s//${LOCALBASE:S/\//\\\//g}/g" \
	    -e "/%%DATADIR%%/s//${DATADIR:S/\//\\\//g}/g" $${FILE}; \
	done;

do-install:
# Scripts
	${MKDIR} ${DATADIR}; \
	cd ${WRKSRC}; \
	FILES=$$(${FIND} . ${FIND_ARGS} ); \
	for FILE in $${FILES}; do \
		${INSTALL_SCRIPT} $${FILE} ${DATADIR}/$${FILE}; \
	done;

# Link to executable
	FILE=merge_pdf; \
	${LN} ${LINK_OPTS} ${DATADIR}/$${FILE} ${PREFIX}/bin/${PORTNAME};

.include <bsd.port.mk>
