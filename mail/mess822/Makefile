# New ports collection makefile for:	mess822
# Date created:		4 February 2001
# Whom:			David Siebörger <drs@rucus.ru.ac.za>
#
# $FreeBSD$
#

PORTNAME=	mess822
PORTVERSION=	0.58
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/ \
		ftp://ftp.jp.qmail.org/qmail/ \
		ftp://ftp.net.ohio-state.edu/pub/networking/mail/qmail/ \
		ftp://mirror.pipex.net/pub/unix/mail/qmail/

MAINTAINER=	drs@rucus.ru.ac.za
COMMENT=	RFC 822 mail message parsing library and rewriting utilities

RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

BROKEN=		"Changes ownership of system directories"

NO_PACKAGE=	Violates djb\'s license
USE_REINPLACE=	yes

ALL_TARGET=	it
INSTALL_TARGET=	setup check

MAN1=		822date.1 822field.1 822header.1 822print.1 822received.1 \
		iftocc.1 new-inject.1
MAN3=		mess822.3 mess822_addr.3 mess822_date.3 mess822_fold.3 \
		mess822_quote.3 mess822_token.3 mess822_when.3
MAN5=		rewriting.5
MAN8=		ofmipd.8 ofmipname.8

.if exists(${PREFIX}/qmail/bin/qmail-send)
QMAIL_DIR?=     ${PREFIX}/qmail
.else
QMAIL_DIR?=     /var/qmail
.endif

NO_MTREE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-O2|${CFLAGS}|" ${WRKSRC}/conf-cc
	@${REINPLACE_CMD} -e "s|.var.qmail|${QMAIL_DIR}|" ${WRKSRC}/conf-qmail
	@${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-home

.include <bsd.port.mk>
