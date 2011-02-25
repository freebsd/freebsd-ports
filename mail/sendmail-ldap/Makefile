# New ports collection makefile for:	sendmail-ldap
# Date created:		15.Jun 2001
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTREVISION=	2
CATEGORIES=	mail ipv6

MAINTAINER=	dinoex@FreeBSD.org

SENDMAIL_WITH_LDAP=	yes
SENDMAIL_WITH_TLS=	yes
.if defined(SENDMAIL_WITH_SUID)
# only for compatibility with sendmail 8.11.x
SENDMAIL_WITH_SASL=	yes
SENDMAIL_WITH_SFIO=	yes
SENDMAIL_WITH_MILTER=	yes
SENDMAIL_PORT?=		sendmail811
.else
SENDMAIL_WITH_SASL2=	yes
SENDMAIL_PORT?=		sendmail
.endif
MASTERDIR?=	${.CURDIR}/../${SENDMAIL_PORT}

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
