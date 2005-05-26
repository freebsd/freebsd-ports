# New ports collection makefile for:	qmail-spamcontrol
# Date created:		2005-02-01
# Whom:			Renato Botelho <renato@galle.com.br>
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${SPAMCONTROL_VERSION}
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES+=	http://www.fehcom.de/qmail/spamcontrol/:spamcontrol
PKGNAMESUFFIX=	-spamcontrol
DISTFILES=	${QMAIL_DIST} ${SPAMCONTROL_DIST}:spamcontrol
EXTRACT_ONLY=	${QMAIL_DIST}

MAINTAINER=	freebsd@galle.com.br
COMMENT=	Qmail MTA with SpamControl patches

EXTRA_PATCHES+=	${MASTERDIR}/files/patch-install.c

# Distfiles
QMAIL_DIST=		${PORTNAME}-${QMAIL_VERSION}${EXTRACT_SUFX}
SPAMCONTROL_DIST=	spamcontrol-${SPAMCONTROL_VERSION}_tgz.bin
SPAMCONTROL_VERSION=	2314
LATEST_LINK=		${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

SLAVE_SPAMCONTROL=	yes

# Local overrides
MASTERDIR=	${.CURDIR}/../qmail
PATCHDIR=	${.CURDIR}/files
DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
