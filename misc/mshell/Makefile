# New ports collection makefile for:    mshell
# Version required:     93/3/3
# Date created:         24 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.6 1995/04/23 13:02:33 asami Exp $
#

DISTNAME=	mshell
PKGNAME=	mshell-1.0
CATEGORIES+=	misc
MASTER_SITES=	ftp://src.doc.ic.ac.uk/usenet/alt.sources/articles/07000-07999/
DISTFILES=	7432.Z

MAINTAINER=	jmz@FreeBSD.org

NO_WRKSUBDIR=	yes

do-extract:
	@rm -rf ${WRKDIR}
	@mkdir -p ${WRKDIR}
	zcat ${DISTDIR}/${DISTFILES} |(cd ${WRKDIR}; \
	awk '{if (/^#!/) x++} {if(x) print $$0'}| /bin/sh)

.include <bsd.port.mk>
