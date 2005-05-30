# New ports collection makefile for:	qmailanalog
# Date created:		29 November 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$
#

PORTNAME=	qmailanalog
PORTVERSION=	0.70
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://cr.yp.to/software/

MAINTAINER=	freebsd@galle.com.br
COMMENT=	A collection of tools to analyze qmail-send's activity

RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

ALL_TARGET=	it
INSTALL_TARGET=	setup

MANPREFIX=	${QMPREFIX}
MAN1=		matchup.1 xqp.1 xsender.1 xrecipient.1 columnt.1

PLIST_SUB+=	MYSUBDIR=${MYSUBDIR}

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

PREFIX?=	${QMAIL_DIR}
QMPREFIX?=	${PREFIX}/${MYSUBDIR}

NO_MTREE=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${PREFIX} != ${QMAIL_DIR}
BROKEN=	"Cannot Make and Install with different PREFIX or QMAIL_DIR"
.endif

post-patch:
	@${REINPLACE_CMD} "s|.usr.local.qmailanalog|${QMPREFIX}|" ${WRKSRC}/conf-home
	@${REINPLACE_CMD} "s|-O2|${CFLAGS}|" ${WRKSRC}/conf-cc
	@${REINPLACE_CMD} 's|02755|0755|g; /cat/d' ${WRKSRC}/hier.c
	@${REINPLACE_CMD} 's|^man prog|prog|g' ${WRKSRC}/Makefile

pre-install:
	@${MKDIR} ${QMPREFIX}

.include <bsd.port.post.mk>
