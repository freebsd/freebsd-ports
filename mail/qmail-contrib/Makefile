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

MAINTAINER=	ports@FreeBSD.org
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

.if (${PREFIX} == "/usr/local")
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
USE_PERL5_BUILD=yes

pre-patch:
	@cd ${WRKFF} \
	&& ${PATCH} -s <${PATCHDIR}/extra-patch-newaliases
#	&& ${PATCH} <${PATCHDIR}/extra-patch-striplocal
#	apparently the above patch is no longer needed

post-patch:
	@perl -pi.bak -e "s|-O2|${CFLAGS}|" ${WRKFF}/conf-cc
	@perl -pi.bak -e "s|.var.qmail|${QMAIL_DIR}|" ${WRKFF}/conf-qmail
	@perl -pi.bak -e '$$_ = "" if /cat/' ${WRKFF}/hier.c
	@perl -pi.bak -e "s|-O2|${CFLAGS}|" ${WRKDF}/conf-cc
	@perl -pi.bak -e "s|.var.qmail|${QMAIL_DIR}|" ${WRKDF}/conf-qmail
	@perl -pi.bak -e '$$_ = "" if /cat/' ${WRKDF}/hier.c

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
