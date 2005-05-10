# New ports collection makefile for:	qmail-mysql
# Date created:				6 Feb 2001
# Whom:					Mario S F Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${MYSQL_PATCH_VERSION}
PORTREVISION=	2
CATEGORIES=	mail
PKGNAMESUFFIX=	-mysql

MAINTAINER=	freebsd@galle.com.br
COMMENT=	A SECURE, reliable, and FAST MTA for UNIX systems WITH MySQL support

MYSQL_PATCH_VERSION=	1.1.8

SLAVE_MYSQL=	yes

USE_MYSQL=	yes

MASTERDIR=	${.CURDIR}/../qmail
DESCR=		${.CURDIR}/pkg-descr
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

.include "${MASTERDIR}/Makefile"
