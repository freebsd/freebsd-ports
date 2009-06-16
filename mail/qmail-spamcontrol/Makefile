# New ports collection makefile for:	qmail-spamcontrol
# Date created:		2005-02-01
# Whom:			Renato Botelho <renato@galle.com.br>
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${SPAMCONTROL_VERSION}
PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES+=	http://www.fehcom.de/qmail/spamcontrol/:spamcontrol \
		${MASTER_SITE_LOCAL:S/$/:spamcontrol/}
MASTER_SITE_SUBDIR=	garga/qmail/:spamcontrol
PKGNAMESUFFIX=	-spamcontrol
DISTFILES=	${QMAIL_DIST} ${SPAMCONTROL_DIST}:spamcontrol
EXTRACT_ONLY=	${QMAIL_DIST}

COMMENT=	Qmail MTA with SpamControl patches

CONFLICTS=	qmail-[0-9]* qmail-ldap-[0-9]* qmail-mysql-[0-9]* qmail-tls-[0-9]*

EXTRA_PATCHES+=	${MASTERDIR}/files/patch-install.c

# Distfiles
QMAIL_DIST=		${PORTNAME}-${QMAIL_VERSION}${EXTRACT_SUFX}
SPAMCONTROL_DIST=	spamcontrol-${SPAMCONTROL_VERSION}_tgz.bin
SPAMCONTROL_VERSION=	2525a
LATEST_LINK=		${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

SLAVE_SPAMCONTROL=	yes

# Local overrides
MASTERDIR=	${.CURDIR}/../qmail
PATCHDIR=	${.CURDIR}/files
DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
