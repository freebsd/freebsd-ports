# New ports collection makefile for:    mshell
# Version required:     93/3/3
# Date created:         24 September 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	mshell
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	ftp://src.doc.ic.ac.uk/usenet/alt.sources/articles/07000-07999/
DISTFILES=	7432.Z

MAINTAINER=	jmz@FreeBSD.org

NO_WRKSUBDIR=	yes
MAN1=		mshell.1

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	zcat ${DISTDIR}/${DISTFILES} |(cd ${WRKDIR}; \
	${AWK} '{if (/^#!/) x++} {if(x) print $$0'}| ${SH})

.include <bsd.port.mk>
