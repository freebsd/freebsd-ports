# New ports collection makefile for:	code2html
# Version required:			0.8.7c
# Date created:				01 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	code2html.pl
PKGNAME=	code2html-0.8.7c
CATEGORIES=	textproc
MASTER_SITES=	http://www.giga.or.at/~weasel/pub/code2html/latest/
EXTRACT_SUFX=	.gz

MAINTAINER=	jedgar@fxp.org

RUN_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@${GZCAT} ${DISTDIR}/${DISTFILES} > ${WRKDIR}/${DISTNAME}

do-configure:
	@${MV} ${WRKSRC}/code2html.pl  ${WRKSRC}/code2html.pl.orig
	@${SED} -e 's|/usr/bin/bzip2|${PREFIX}/bin/bzip2|' \
		-e 's|/bin/gzip|/usr/bin/gzip|' \
		-e 's|/etc/code|${PREFIX}/etc/code|' \
		< ${WRKSRC}/code2html.pl.orig > ${WRKSRC}/code2html.pl

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/code2html.pl ${PREFIX}/bin/code2html

.include <bsd.port.mk>
