# New ports collection makefile for:    mshell
# Version required:     93/3/3
# Date created:         24 September 1994
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	mshell
PKGNAME=	mshell-1.0
CATEGORIES+=	utilities
MASTER_SITES=	ftp://src.doc.ic.ac.uk/usenet/alt.sources/articles/07000-07999/
DISTFILES=	7432.Z

MAINTAINER=	jmz@FreeBSD.org

NO_WRKSUBDIR=	yes

EXTRACT_COOKIE?=	${.CURDIR}/.extract_done

extract: fetch pre-extract ${EXTRACT_COOKIE}

${EXTRACT_COOKIE}:
	@echo "===>  Extracting for ${DISTNAME}"
	@rm -rf ${WRKDIR}
	@mkdir -p ${WRKDIR}
	zcat ${DISTDIR}/${DISTFILES} |(cd ${WRKDIR}; \
	awk '{if (/^#!/) x++} {if(x) print $$0'}| /bin/sh)
	@touch -f ${EXTRACT_COOKIE}

.include <bsd.port.mk>
