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

PATCH_SITES+=	http://iain.cx/unix/qmail/download/
PATCHFILES+=	qmail-mysql-${MYSQL_PATCH_VERSION}.patch

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

# patches from the master port that brake this one are now allowed
MAIN_QMAIL_PORT_WITH_QMAILQUEUE_PATCH_BARRIER=	yes

MYSQL_PATCH_VERSION=	1.1.8

# Using default from master port, i.e., /var/qmail
PREFIX?=	${QMAIL_PORT_PREFIX}
#PREFIX=		/var/qmail-mysql

.if !defined(PRE_MK_INCLUDED)
.include <bsd.port.pre.mk>
.endif

#QMAIL_PORT=	${PORTSDIR}/mail/qmail
QMAIL_PORT=	${.CURDIR}/../qmail
QMAIL_PORT_PREFIX!=	cd ${QMAIL_PORT} && ${MAKE} -V PREFIX

# Yet anther ugly hack (works due to code inside the main qmail port)
slaveport-post-patch: qmail-mysql-post-patch

qmail-mysql-post-patch:
	@${PERL} -pi -ne \
		 's|/opt/mysql|${LOCALBASE}|' \
			${WRKSRC}/Makefile

# Local overrides
MASTERDIR=	${QMAIL_PORT}
PKGDIR_LOCAL=	${.CURDIR}
COMMENT=	${PKGDIR_LOCAL}/pkg-comment
DESCR=		${PKGDIR_LOCAL}/pkg-descr
PKGMESSAGE=	${PKGDIR_LOCAL}/pkg-message

PRE_MK_INCLUDED=	yes

.include "${MASTERDIR}/Makefile"
