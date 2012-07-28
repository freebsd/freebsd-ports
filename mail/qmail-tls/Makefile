# New ports collection makefile for:	qmail-tls
# Date created:				03 Dec 2000
# Whom:					Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${TLS_PATCH_DATE}
PORTREVISION=	4
CATEGORIES=	mail
PKGNAMESUFFIX=	-tls

COMMENT=	Secure, reliable, and fast MTA for UNIX systems with TLS support

CONFLICTS=	qmail-[0-9]* qmail-ldap-[0-9]* qmail-mysql-[0-9]* qmail-spamcontrol-[0-9]*

SLAVE_TLS=	yes

TLS_PATCH_DATE=	20021228

USE_OPENSSL=	yes

# Local overrides
MASTERDIR=	${.CURDIR}/../qmail
DESCR=		${.CURDIR}/pkg-descr
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

.include "${MASTERDIR}/Makefile"
