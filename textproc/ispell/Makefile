# New ports collection makefile for:    ispell
# Version required:     3.1.18
# Date created:         6 November 1994
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	ispell-3.1
PKGNAME=	ispell-3.1.18
CATEGORIES+=	utilities
MASTER_SITES=	ftp://ftp.cs.ucla.edu/pub/ispell-3.1/
DISTFILES=	ispell-3.1.18.tar.gz

MAINTAINER=	jmz@FreeBSD.org

# French
#EXTRA_DICT=	   francais-IREQ-1.3.tar.gz
#MASTER_SITES+=    ftp://ftp.ireq-robot.hydro.qc.ca/pub/ispell/

DISTFILES+=	   ${EXTRA_DICT}

MAKE_FLAGS=	TMPDIR=${.CURDIR} -f 

pre-configure:
.if defined(EXTRA_DICT)
	@echo ${EXTRA_DICT} > ${WRKDIR}/extra_dict
.else
	@echo -n
.endif

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/man/man4

.include <bsd.port.mk>
