# New ports collection makefile for:	qmail-mysql
# Date created:				6 Feb 2001
# Whom:					Mario S F Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${MYSQL_PATCH_VERSION}
PORTREVISION=	1
CATEGORIES=	mail
PKGNAMESUFFIX=	-mysql

PATCH_SITES+=	http://iain.cx/unix/qmail/download/:mysql
PATCHFILES+=	qmail-mysql-${MYSQL_PATCH_VERSION}.patch:mysql

MAINTAINER=	freebsd@galle.com.br
COMMENT=	A SECURE, reliable, and FAST MTA for UNIX systems WITH MySQL support

USE_MYSQL=	yes
USE_REINPLACE=	yes

# patches from the master port that brake this one are now allowed
MAIN_QMAIL_PORT_WITH_QMAILQUEUE_PATCH_BARRIER=	yes

MYSQL_PATCH_VERSION=	1.1.8

# Using default from master port, i.e., /var/qmail
PREFIX?=	${QMAIL_PORT_PREFIX}

.if !defined(_PREMKINCLUDED)
.include <bsd.port.pre.mk>
.endif

# Local overrides
MASTERDIR=	${.CURDIR}/../qmail
PKGDIR_LOCAL=	${.CURDIR}
DESCR=		${PKGDIR_LOCAL}/pkg-descr
PKGMESSAGE=	${PKGDIR_LOCAL}/pkg-message

QMAIL_PORT_PREFIX!=	cd ${MASTERDIR} && ${MAKE} -V PREFIX

# Yet anther ugly hack (works due to code inside the main qmail port)
slaveport-post-patch: qmail-mysql-post-patch

qmail-mysql-post-patch:
	@${REINPLACE_CMD} \
		 's|/opt/mysql|${LOCALBASE}|' \
			${WRKSRC}/Makefile

.include "${MASTERDIR}/Makefile"
