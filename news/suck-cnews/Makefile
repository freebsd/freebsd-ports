# New ports collection makefile for:	suck (cnews)
# Date created:		22 May 2001
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

CATEGORIES=	news

MAINTAINER=	dinoex@FreeBSD.org

MASTERDIR=	${.CURDIR}/../suck

VARBASE?=	/var
NEWSBIN?=	${PREFIX}/libexec/cnews
NEWSCTL?=	${VARBASE}/lib/news

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
