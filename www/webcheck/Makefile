# New ports collection makefile for: webcheck
# Date created:        10 May, 2002
# Whom:                Mike Meyer <mwm@mired.org>
#
# $FreeBSD$
#

PORTNAME=	webcheck
PORTVERSION=	1.0
CATEGORIES=	www python
MASTER_SITES=	http://www.mired.org/webcheck/
EXTRACT_SUFX=	.bz2

MAINTAINER=	mwm@mired.org
COMMENT=	View structure of a web site, get a list of problems like broken links

USE_PYTHON=	YES
USE_BZIP2=	YES
.if defined(NOPORTDOCS)
NO_BUILD=	YES
.endif

do-build:
	${AWK} '/^Running Webcheck/ { output=1 } output' \
		< ${WRKSRC}/INSTALL > ${WRKSRC}/USAGE

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.py ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.css ${DATADIR}
.for d in plugins schemes
	@${MKDIR} ${DATADIR}/${d}
	${INSTALL_DATA} ${WRKSRC}/${d}/*.py ${DATADIR}/${d}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/webcheck.py ${DATADIR}
	${LN} -sf ${DATADIR}/webcheck.py ${PREFIX}/bin/webcheck
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/USAGE ${DOCSDIR}
.endif

.include <bsd.port.mk>
