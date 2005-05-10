# New ports collection makefile for:	qmail-smtp_auth+tls
# Date created:				03 Dec 2000
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org> et. al.
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${SMTP_AUTH-TLS_PATCH_DATE}
PORTREVISION=	1
CATEGORIES=	mail
PKGNAMESUFFIX=	-smtp_auth+tls

MAINTAINER=	freebsd@galle.com.br
COMMENT=	A SECURE, reliable, and FAST MTA for UNIX systems WITH SMTP_AUTH+TLS

# not type-safe
ONLY_FOR_ARCHS=	i386

USE_OPENSSL=	yes

SLAVE_SMTP_AUTH_TLS=	yes

SMTP_AUTH-TLS_PATCH_DATE=	20020519

# Local overrides
MASTERDIR=	${.CURDIR}/../qmail
DESCR=		${.CURDIR}/pkg-descr
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

.include "${MASTERDIR}/Makefile"
