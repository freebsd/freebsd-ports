# Created by: Mario S F Ferreira <lioux@linf.unb.br>
# $FreeBSD$

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${TLS_PATCH_DATE}
PORTREVISION=	1
CATEGORIES=	mail
PKGNAMESUFFIX=	-tls

COMMENT=	Secure, reliable, and fast MTA for UNIX systems with TLS support

CONFLICTS=	*qmail-[0-9]* qmail-ldap-[0-9]* *qmail-mysql-[0-9]* qmail-spamcontrol-[0-9]*

SLAVE_TLS=	yes

TLS_PATCH_DATE=	20110119

USE_OPENSSL=	yes

# Local overrides
MASTERDIR=	${.CURDIR}/../qmail
DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
