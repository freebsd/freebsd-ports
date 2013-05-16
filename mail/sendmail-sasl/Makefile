# $FreeBSD$

CATEGORIES=	mail ipv6

MAINTAINER=	dinoex@FreeBSD.org

WITH_TLS=	yes
WITH_SASL2=	yes
SENDMAIL_PORT?=		sendmail
MASTERDIR?=	${.CURDIR}/../${SENDMAIL_PORT}

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
