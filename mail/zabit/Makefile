# New ports collection makefile for:   zabit
# Date created:                 14 May 2005
# Whom:                         Ozkan KIRIK <ozkan@enderunix.org>
#
# $FreeBSD$
#

PORTNAME=	zabit
PORTVERSION=	0.7.1
CATEGORIES=	mail
MASTER_SITES=	http://www.enderunix.org/zabit/

MAINTAINER=	ozkan@enderunix.org
COMMENT=	Zabit is a content/attachment filter for qmail

RUN_DEPENDS=	${QMAIL_QUEUE}:${PORTSDIR}/mail/qmail

HAS_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/qmail/bin/qmail-queue)
QMAIL_DIR?=     ${LOCALBASE}/qmail
.else
QMAIL_DIR?=     /var/qmail
.endif
QMAIL_QUEUE=    ${QMAIL_DIR}/bin/qmail-queue

pre-build:
.if !defined(BATCH)
	@${DIALOG} --title "${PORTNAME} - ${PORTVERSION} Configuration Menu"\
		--menu "Choose your locale for case insensitive search" 20 60 13\
		en_US English\
		tr_TR Turkish\
		2>${WRKSRC}/conf-locale
.else
	@${ECHO_CMD} "en_US" > ${WRKSRC}/conf-locale
.endif
	@${ECHO_CMD} >> ${WRKSRC}/conf-locale
	@${ECHO_MSG} "===> Locale: `cat ${WRKSRC}/conf-locale`"

.include <bsd.port.post.mk>
