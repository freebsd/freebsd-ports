# New ports collection makefile for:	p5-Apache-DBI-mp2
# Date created:				            28 Aug 2008
# Whom:					                Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	Apache-DBI
PKGNAMESUFFIX=	-mp2

COMMENT=	DBI persistent connection, authentication and authorization (mp2)

MAKE_JOBS_SAFE=  yes

MASTERDIR=	${.CURDIR}/../p5-Apache-DBI

.if defined(WITH_MODPERL) || defined(WITHOUT_MODPERL2)
IGNORE=	This port is only for use with www/mod_perl2
.endif

WITH_MODPERL2=	yes

.include "${MASTERDIR}/Makefile"
