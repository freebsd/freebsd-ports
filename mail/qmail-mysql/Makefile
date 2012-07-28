# New ports collection makefile for:	qmail-mysql
# Date created:				6 Feb 2001
# Whom:					Mario S F Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${MYSQL_PATCH_VERSION}
PORTREVISION=	3
CATEGORIES=	mail
PKGNAMESUFFIX=	-mysql

COMMENT=	Secure, reliable, and fast MTA for UNIX systems with MySQL support

CONFLICTS=	qmail-[0-9]* qmail-ldap-[0-9]* qmail-spamcontrol-[0-9]* qmail-tls-[0-9]*

MYSQL_PATCH_VERSION=	1.1.15

SLAVE_MYSQL=	yes

USE_MYSQL=	yes

MASTERDIR=	${.CURDIR}/../qmail
DESCR=		${.CURDIR}/pkg-descr
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

.include "${MASTERDIR}/Makefile"
