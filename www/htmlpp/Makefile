# New ports collection makefile for:    htmlpp
# Date created:         9 Nov 1997
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	htmlpp
PORTVERSION=	4.2a
CATEGORIES=	www
MASTER_SITES=	http://www.imatix.com/pub/tools/
DISTNAME=	htmlp42a
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Perl script to allow easy creation of HTML from template files

USE_PERL5=	YES

NO_WRKSUBDIR=	yes

do-build:
	${SED} -e '1,1s:/usr/bin/perl:${PERL5}:' \
		${WRKDIR}/htmlpp > ${WRKDIR}/htmlpp.temp
	${RM} -f ${WRKDIR}/htmlpp
	${MV} ${WRKDIR}/htmlpp.temp ${WRKDIR}/htmlpp

do-install:
	${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}
	${INSTALL_SCRIPT} ${WRKDIR}/htmlpp ${PREFIX}/bin/htmlpp
	${INSTALL_DATA} ${WRKDIR}/htmlpp.d ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/htmlpp.d
	(cd ${WRKDIR}; for FILE in *.pl; do ${INSTALL_DATA} $${FILE} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/$${FILE}; done)
	(cd ${WRKDIR}; for FILE in *.def; do ${INSTALL_DATA} $${FILE} ${PREFIX}/bin/$${FILE}; done)
	${INSTALL_DATA} ${WRKDIR}/guru_opt.fmt ${PREFIX}/bin/guru.fmt
	(cd ${WRKDIR}; ${MKDIR} ${PREFIX}/share/doc/htmlpp; for FILE in *.htm; do ${INSTALL_DATA} $${FILE} ${PREFIX}/share/doc/htmlpp/$${FILE}; done)
	(cd ${WRKDIR}; for FILE in *.gif; do ${INSTALL_DATA} $${FILE} ${PREFIX}/share/doc/htmlpp/$${FILE}; done)
	(cd ${WRKDIR}; for FILE in *.txt; do ${INSTALL_DATA} $${FILE} ${PREFIX}/share/doc/htmlpp/$${FILE}; done)

.include <bsd.port.mk>
