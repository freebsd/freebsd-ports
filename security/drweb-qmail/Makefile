# New ports collection makefile for:	drweb-qmail
# Date created:				5 February 2003
# Whom:					Denis N. Peplin <info@volginfo.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb_qmail
PORTVERSION=	4.29.12
PORTREVISION=	2
CATEGORIES=	security mail
MASTER_SITES=	ftp://ftp.drweb.ru/pub/unix/

MAINTAINER=	info@volginfo.ru
COMMENT=	Qmail client for DrWeb antivirus suite

RUN_DEPENDS=	${DRWEB_PREFIX}/drwebd:${PORTSDIR}/security/drweb \
			${QMAIL_PREFIX}/bin/qmail-queue:${PORTSDIR}/mail/qmail

ONLY_FOR_ARCHS=	i386
NO_BUILD=	YES
RESTRICTED=	"non-commercial or evaluation use"
NO_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/drweb-qmail

QMAIL_PREFIX?=	/var/qmail
QMAIL_NOFILES?=	qnofiles

DRWEB_WRKDIR=	/var/drweb
DRWEB_PREFIX=	${PREFIX}/drweb

PW_CMD?=	/usr/sbin/pw

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500000
DISTNAME=	drweb-qmail-${PORTVERSION}-F-freebsd5
.else
DISTNAME=	drweb-qmail-${PORTVERSION}-F-freebsd4
.endif

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can use QMAIL_PREFIX (default value is /var/qmail) and QMAIL_NOFILES (default value is qnofiles) options."
	@${ECHO_MSG} ""

BINOWN=		drweb
BINGRP=		qmail
BINMODE=	4711

do-install:
	${PW_CMD} usermod drweb -G ${QMAIL_NOFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/opt/drweb/qmail-queue \
		${QMAIL_PREFIX}/bin/qmail-queue.drweb
	${INSTALL_DATA} ${WRKSRC}/etc/drweb/addresses.conf \
		${DRWEB_PREFIX}/addresses.conf-dist
	${INSTALL_DATA} ${WRKSRC}/etc/drweb/drweb_qmail.conf \
		${DRWEB_PREFIX}/drweb_qmail.conf-dist
	${INSTALL_DATA} ${WRKSRC}/etc/drweb/users.conf \
		${DRWEB_PREFIX}/users.conf-dist
	${INSTALL_DATA} ${WRKSRC}/etc/drweb/viruses.conf \
		${DRWEB_PREFIX}/viruses.conf-dist
	if [ ! -f ${DRWEB_PREFIX}/addresses.conf ] ; then \
		${CP} ${DRWEB_PREFIX}/addresses.conf-dist \
		      ${DRWEB_PREFIX}/addresses.conf; \
	fi
	if [ ! -f ${DRWEB_PREFIX}/drweb_qmail.conf ] ; then \
		${CP} ${DRWEB_PREFIX}/drweb_qmail.conf-dist \
		      ${DRWEB_PREFIX}/drweb_qmail.conf; \
	fi
	if [ ! -f ${DRWEB_PREFIX}/users.conf ] ; then \
		${CP} ${DRWEB_PREFIX}/users.conf-dist \
		      ${DRWEB_PREFIX}/users.conf; \
	fi
	if [ ! -f ${DRWEB_PREFIX}/viruses.conf ] ; then \
		${CP} ${DRWEB_PREFIX}/viruses.conf-dist \
		      ${DRWEB_PREFIX}/viruses.conf; \
	fi
	${MKDIR} -m 755 ${DRWEB_WRKDIR}
	${MKDIR} -m 770 ${DRWEB_WRKDIR}/infected ${DRWEB_WRKDIR}/spool
	${CHOWN} drweb:drweb ${DRWEB_WRKDIR}
	${CHOWN} drweb:${QMAIL_NOFILES} ${DRWEB_WRKDIR}/infected \
		${DRWEB_WRKDIR}/spool
	${CP} -R ${WRKSRC}/etc/drweb/templates ${PREFIX}/drweb
	${CP} -R ${WRKSRC}/opt/drweb/doc/qmail ${PREFIX}/drweb/doc

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
