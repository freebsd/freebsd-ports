# $FreeBSD$

PORTREVISION=	2
CATEGORIES=	mail ipv6

MAINTAINER=	dinoex@FreeBSD.org

WITH_LDAP=	yes
WITH_TLS=	yes
WITH_SASL2=	yes
SENDMAIL_PORT?=		sendmail
MASTERDIR?=	${.CURDIR}/../${SENDMAIL_PORT}

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
