# New ports collection makefile for:	qmail-ldap
# Date created:				21 May 2000
# Whom:					Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${LDAP_PATCH_DATE}
PORTREVISION=	3
CATEGORIES=	mail
PKGNAMESUFFIX=	-ldap

MAINTAINER=	freebsd@galle.com.br
COMMENT=	A SECURE, reliable, and FAST MTA for UNIX systems WITH LDAP support

EXTRA_PATCHES+=	${MASTERDIR}/files/patch-install.c
PATCH_DIST_STRIP+=	-p1

CONFLICTS=	nss-[0-9]* emboss-[0-9]* digest-[0-9]*

USE_OPENLDAP=	yes
SLAVE_LDAP=	yes
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}2

.if !defined(WITHOUT_TLS)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-with_tls
USE_OPENSSL=	yes
.endif

LDAP_PATCH_DATE=	20020901

MASTERDIR=	${.CURDIR}/../qmail
DESCR=		${.CURDIR}/pkg-descr
PATCHDIR=	${.CURDIR}/files
LATEST_LINK=	${PORTNAME}-ldap

.include "${MASTERDIR}/Makefile"
