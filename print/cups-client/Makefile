# New ports collection makefile for:	cups-client
# Date created:		07.May 2009
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

CATEGORIES=	print

MAINTAINER=	dinoex@FreeBSD.org

MASTERDIR?=	${.CURDIR}/../cups-base
 
CUPS_CLIENT=	yes

OPTIONS=	GNUTLS		"Build with GNUTLS library" on

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
