# New ports collection makefile for:	ezmlm
# Version required:     0.53
# Date created:		28 November 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $Id$
#

DISTNAME=       ezmlm-0.53
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.id.wustl.edu/pub/patches/

MAINTAINER=	ports@freebsd.org

RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

ALL_TARGET=	it
INSTALL_TARGET=	setup

MAN1=		ezmlm-list.1 ezmlm-make.1 ezmlm-manage.1 ezmlm-reject.1
MAN1+=		ezmlm-return.1 ezmlm-send.1 ezmlm-sub.1 ezmlm-unsub.1
MAN1+=		ezmlm-warn.1 ezmlm-weed.1
MAN5=		ezmlm.5

DIFF_MSG=       Cannot Make and Install with different PREFIX or QMAIL_DIR

.if exists(${PREFIX}/qmail/bin/qmail-send)
QMAIL_DIR?=	${PREFIX}/qmail
.else
QMAIL_DIR?=	/var/qmail
.endif

post-patch:
	@perl -pi.bak -e "s|.usr.local.bin.ezmlm|${PREFIX}/bin|" ${WRKSRC}/conf-bin
	@perl -pi.bak -e "s|.usr.local|${PREFIX}|" ${WRKSRC}/conf-man
	@perl -pi.bak -e "s|.var.qmail|${QMAIL_DIR}|" ${WRKSRC}/conf-qmail
	@perl -pi.bak -e "s|-O2|${CFLAGS}|" ${WRKSRC}/conf-cc
	@perl -pi.bak -e '$$_ = "" if /cat/' ${WRKSRC}/MAN
	@echo ${PREFIX} > ${WRKDIR}/.PPREFIX
	@echo ${QMAIL_DIR} >> ${WRKDIR}/.PPREFIX

pre-install:
	@echo ${PREFIX} > ${WRKDIR}/.IPREFIX
	@echo ${QMAIL_DIR} >> ${WRKDIR}/.IPREFIX
	@diff ${WRKDIR}/.[PI]PREFIX > /dev/null \
	|| (echo ${DIFF_MSG} && exit 1)

.include <bsd.port.mk>
