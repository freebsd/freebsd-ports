# New ports collection makefile for:	OpenSSL-stable
# Date created:		04.Okt 2005
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

CATEGORIES=	security devel

MAINTAINER=	dinoex@FreeBSD.org

MASTERDIR?=	${.CURDIR}/../openssl
WITH_OPENSSL_STABLE=	yes

DEPRICATED=	OpenSSSL 0.9.8 is out
EXPIRATION_DATE=2008-11-01

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
