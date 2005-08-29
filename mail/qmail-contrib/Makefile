# New ports collection makefile for:	qmail-contrib
# Date created:		28 November 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$
#

PORTNAME=	qmail-contrib
PORTVERSION=	0.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.qmail.org/pub/software/ \
		ftp://rucus.ru.ac.za/pub/mail/qmail/src/
DISTFILES=	dot-forward-${DF_VER}.tar.gz \
		fastforward-${FF_VER}.tar.gz

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Contributed programs for qmail

RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

NO_PACKAGE=	Unsure of djb\'s license

ALL_TARGET=	it
INSTALL_TARGET=	setup

MAN1=		dot-forward.1 fastforward.1 printforward.1 setforward.1
MAN1+=		newaliases.1 printmaillist.1 setmaillist.1 newinclude.1

PLIST_SUB=	DOCDIR=${DOCDIR}

.if exists(${PREFIX}/qmail/bin/qmail-send)
QMAIL_DIR?=	${PREFIX}/qmail
PREFIX?=	${PREFIX}/qmail
.else
QMAIL_DIR?=	/var/qmail
PREFIX?=	/var/qmail
.endif

.if (${PREFIX} == ${LOCALBASE})
DOCDIR=		share/doc/qmail
.else
DOCDIR=		doc
.endif

FF_VER=		0.51
DF_VER=		0.71
QCK_VER=	0.1

WRKFF=		${WRKDIR}/fastforward-${FF_VER}
WRKDF=		${WRKDIR}/dot-forward-${DF_VER}

NO_MTREE=	yes

USE_REINPLACE=	yes

pre-patch:
	@cd ${WRKFF} \
	&& ${PATCH} -s <${PATCHDIR}/extra-patch-newaliases

post-patch:
	@${REINPLACE_CMD} -e "s|-O2|${CFLAGS}|" ${WRKFF}/conf-cc
	@${REINPLACE_CMD} -e "s|.var.qmail|${QMAIL_DIR}|" ${WRKFF}/conf-qmail
	@${REINPLACE_CMD} -e '/cat/d' ${WRKFF}/hier.c
	@${REINPLACE_CMD} -e "s|-O2|${CFLAGS}|" ${WRKDF}/conf-cc
	@${REINPLACE_CMD} -e "s|.var.qmail|${QMAIL_DIR}|" ${WRKDF}/conf-qmail
	@${REINPLACE_CMD} -e '/cat/d' ${WRKDF}/hier.c

do-build:
	@cd ${WRKDIR}/dot-forward-${DF_VER} \
	&& make ${ALL_TARGET}
	@cd ${WRKDIR}/fastforward-${FF_VER} \
	&& make ${ALL_TARGET}

do-install:
	@cd ${WRKDIR}/dot-forward-${DF_VER} \
	&& make ${INSTALL_TARGET}
	@cd ${WRKDIR}/fastforward-${FF_VER} \
	&& make ${INSTALL_TARGET}

.include <bsd.port.mk>
