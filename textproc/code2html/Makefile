# New ports collection makefile for:	code2html
# Version required:			0.8.8a
# Date created:				01 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	code2html
PKGNAME=	code2html-0.8.8a
CATEGORIES=	textproc
MASTER_SITES=	http://ckb.dhs.org/projects/code2html/latest/ \
		http://www.cosy.sbg.ac.at/~ppalfrad/code2html/all/latest/
EXTRACT_SUFX=	.gz

MAINTAINER=	jedgar@FreeBSD.org

RUN_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@${GZCAT} ${DISTDIR}/${DISTFILES} > ${WRKDIR}/${DISTNAME}

do-configure:
	@${MV} ${WRKSRC}/code2html ${WRKSRC}/code2html.orig
	@${SED} -e 's|/usr/bin/bzip2|${PREFIX}/bin/bzip2|' \
		-e 's|/bin/gzip|/usr/bin/gzip|' \
		-e 's|/etc/code|${PREFIX}/etc/code|' \
		< ${WRKSRC}/code2html.orig > ${WRKSRC}/code2html

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/code2html ${PREFIX}/bin/

.include <bsd.port.mk>
