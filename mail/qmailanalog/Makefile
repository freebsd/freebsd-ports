# New ports collection makefile for:	qmailanalog
# Date created:		29 November 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$
#

PORTNAME=	qmailanalog
PORTVERSION=	0.70
CATEGORIES=	mail
MASTER_SITES=	ftp://cr.yp.to/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of tools to analyze qmail-send's activity

RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

ALL_TARGET=	it
INSTALL_TARGET=	setup

MANPREFIX=	${QMPREFIX}
MAN1=		matchup.1 xqp.1 xsender.1 xrecipient.1 columnt.1

PLIST_SUB+=	MYSUBDIR=${MYSUBDIR}

DIFF_MSG=	Cannot Make and Install with different PREFIX or QMAIL_DIR

.if exists(${PREFIX}/qmail/bin/qmail-send)
QMAIL_DIR?=	${PREFIX}/qmail
.else
QMAIL_DIR?=	/var/qmail
.endif

.if !defined(NOSUBDIR)
MYSUBDIR?=	qmailanalog/
.else
MYSUBDIR?=
.endif

QMPREFIX?=	${PREFIX}/${MYSUBDIR}

NO_MTREE=	yes
USE_PERL5_BUILD=yes

post-patch:
	@perl -pi.bak -e "s|.usr.local.qmailanalog|${QMPREFIX}|" ${WRKSRC}/conf-home
	@perl -pi.bak -e "s|-O2|${CFLAGS}|" ${WRKSRC}/conf-cc
	@perl -pi.bak -e '$$_ = "" if /cat/' ${WRKSRC}/hier.c
	@${ECHO_CMD} ${PREFIX} > ${WRKDIR}/.PPREFIX
	@${ECHO_CMD} ${QMAIL_DIR} >> ${WRKDIR}/.PPREFIX

pre-install:
	@${ECHO_CMD} ${PREFIX} > ${WRKDIR}/.IPREFIX
	@${ECHO_CMD} ${QMAIL_DIR} >> ${WRKDIR}/.IPREFIX
	@diff ${WRKDIR}/.[PI]PREFIX > /dev/null \
	|| (${ECHO_CMD} ${DIFF_MSG} && exit 1)
	@${MKDIR} ${QMPREFIX}

.include <bsd.port.mk>
