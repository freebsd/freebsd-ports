# New ports collection makefile for:	sendmail-ldap
# Date created:		15.Jun 2001
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

SENDMAIL_WITH_LDAP=	yes
SENDMAIL_WITH_SASL=	yes
SENDMAIL_WITH_TLS=	yes
SENDMAIL_WITH_SFIO=	yes
SENDMAIL_WITH_MILTER=	yes
PKGNAMESUFFIX?=	-ldap
MASTERDIR?=	${.CURDIR}/../sendmail

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
