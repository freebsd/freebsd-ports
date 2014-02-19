# $FreeBSD$

CATEGORIES=	mail ipv6

MAINTAINER=	dinoex@FreeBSD.org

OPTIONS_SET+=	TLS SASL SASLAUTHD
MASTERDIR?=	${.CURDIR}/../sendmail

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
