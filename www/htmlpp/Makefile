# New ports collection makefile for:    htmlpp
# Version required:     3.9d
# Date created:         9 Nov 1997
# Whom:                 Donald Burr <dburr@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1998/11/29 08:20:30 asami Exp $
#

DISTNAME=	htmlpp
PKGNAME=	htmlpp-3.9d
CATEGORIES=	www
MASTER_SITES=	http://www.imatix.com/pub/tools/
EXTRACT_SUFX=	.zip

MAINTAINER=	dburr@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-qa
EXTRACT_AFTER_ARGS=	# empty

USE_PERL5=	YES

NO_WRKSUBDIR=	yes

do-build:
	${SED} -e '1,1s:/usr/bin/perl:${PERL5}:' \
		${WRKDIR}/htmlpp > ${WRKDIR}/htmlpp.temp
	${RM} -f ${WRKDIR}/htmlpp
	${MV} ${WRKDIR}/htmlpp.temp ${WRKDIR}/htmlpp

do-install:
	${MKDIR} ${PREFIX}/lib/perl5/site_perl
	${INSTALL_SCRIPT} ${WRKDIR}/htmlpp ${PREFIX}/bin/htmlpp
	${INSTALL_DATA} ${WRKDIR}/htmlpp.d ${PREFIX}/lib/perl5/site_perl/htmlpp.d
	(cd ${WRKDIR}; for FILE in *.pl; do ${INSTALL_DATA} $${FILE} ${PREFIX}/lib/perl5/site_perl/$${FILE}; done)
	(cd ${WRKDIR}; for FILE in *.def; do ${INSTALL_DATA} $${FILE} ${PREFIX}/bin/$${FILE}; done)
	${INSTALL_DATA} ${WRKDIR}/guru_opt.fmt ${PREFIX}/bin/guru.fmt
	${INSTALL_DATA} ${WRKDIR}/htmlpp.l ${PREFIX}/bin/htmlpp.l
	(cd ${WRKDIR}; ${MKDIR} ${PREFIX}/share/doc/htmlpp; for FILE in *.htm; do ${INSTALL_DATA} $${FILE} ${PREFIX}/share/doc/htmlpp/$${FILE}l; done)
	(cd ${WRKDIR}; for FILE in *.gif; do ${INSTALL_DATA} $${FILE} ${PREFIX}/share/doc/htmlpp/$${FILE}; done)
	(cd ${WRKDIR}; for FILE in *.txt; do ${INSTALL_DATA} $${FILE} ${PREFIX}/share/doc/htmlpp/$${FILE}; done)

.include <bsd.port.mk>
