# New ports collection makefile for:	code2html
# Version required:			0.8.6
# Date created:				01 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	code2html.pl
PKGNAME=	code2html-0.8.6
CATEGORIES=	textproc
MASTER_SITES=	http://www.giga.or.at/~weasel/pub/code2html/latest/
EXTRACT_SUFX=	.gz

MAINTAINER=	jedgar@fxp.org

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	${GZCAT} ${DISTDIR}/${DISTFILES} > ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/code2html.pl ${PREFIX}/bin/code2html

.include <bsd.port.mk>
