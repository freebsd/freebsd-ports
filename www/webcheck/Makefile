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

USE_PYTHON=	YES
USE_BZIP2=	YES

do-install:
	@${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/*.py ${DATADIR}
	${CP} ${WRKSRC}/*.css ${DATADIR}
.for d in plugins schemes
	@${MKDIR} ${DATADIR}/${d}
	${CP} ${WRKSRC}/${d}/*.py ${DATADIR}/${d}
.endfor
	${LN} -sf ${DATADIR}/webcheck.py ${PREFIX}/bin/webcheck
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/USAGE ${DOCSDIR}

do-build:
	${AWK} '/^Running Webcheck/ { output=1 } output' \
		< ${WRKSRC}/INSTALL > ${WRKSRC}/USAGE
.else
NO_BUILD=	yes
.endif

.include <bsd.port.mk>
