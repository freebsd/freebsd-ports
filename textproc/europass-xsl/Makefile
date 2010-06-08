# New ports collection makefile for:	europass-xsl
# Date created:		25 Dec 2008
# Whom:			Gabor Kovesdan <gabor@kovesdan.org>
#
# $FreeBSD$

PORTNAME=	europass-xsl
PORTVERSION=	2.0
CATEGORIES=	textproc
MASTER_SITES=	http://europass.cedefop.europa.eu/TechnicalResources/XML/europass-xsl/
DISTNAME=	${PORTNAME}-V${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XSL stylesheets to transform Europass documents to HTML

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${PREFIX}/share/xsl/europass
	files=$$(${FIND} ${WRKDIR} -type f -depth 1 | ${GREP} -v "/\."); \
	for f in $${files}; do \
		${INSTALL_DATA} $${f} ${PREFIX}/share/xsl/europass; \
	done

plist: do-extract
	${FIND} ${WRKDIR} -type f -depth 1 \
		| ${GREP} -v "/\." | ${SORT} \
		| ${SED} 's|${WRKDIR}/|share/xsl/europass/|g' >${PLIST}
	${ECHO_CMD} "@dirrm share/xsl/europass" >>${PLIST}
	${ECHO_CMD} "@dirrmtry share/xsl" >>${PLIST}

.include <bsd.port.mk>
