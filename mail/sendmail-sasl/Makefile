# New ports collection makefile for:	sendmail-sasl
# Date created:		15.Jun 2001
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PKGNAMESUFFIX?=	-sasl

MAINTAINER=	dinoex@FreeBSD.org

SENDMAIL_WITH_TLS=	yes
.if defined(SENDMAIL_WITH_SUID)
# only for compatibility with sendmail 8.11.x
SENDMAIL_WITH_SASL=	yes
SENDMAIL_WITH_SFIO=	yes
SENDMAIL_WITH_MILTER=	yes
MASTERDIR?=	${.CURDIR}/../sendmail-old
.else
SENDMAIL_WITH_SASL2=	yes
MASTERDIR?=	${.CURDIR}/../sendmail
.endif

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
