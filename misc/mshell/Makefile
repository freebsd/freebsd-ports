# New ports collection makefile for:    mshell
# Date created:         24 September 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	mshell
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz
DISTFILES=	7432.Z

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	A Unix menuing shell

NO_WRKSUBDIR=	yes
MAN1=		mshell.1

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	zcat ${DISTDIR}/${DISTFILES} |(cd ${WRKDIR}; \
	${AWK} '{if (/^#!/) x++} {if(x) print $$0'}| ${SH})

.include <bsd.port.mk>
