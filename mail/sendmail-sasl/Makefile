# $FreeBSD$

CATEGORIES=	mail ipv6

MAINTAINER=	dinoex@FreeBSD.org

WITH_TLS=	yes
WITH_SASL=	yes
WITH_SASLAUTHD=	yes
SENDMAIL_PORT?=		sendmail
MASTERDIR?=	${.CURDIR}/../${SENDMAIL_PORT}

.if exists(${.CURDIR}/Makefile.local)
NO_STAGE=	yes
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
