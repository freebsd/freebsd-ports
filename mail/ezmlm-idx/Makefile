# New ports collection makefile for:	ezmlm
# Version required:     0.313
# Date created:		28 November 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $Id: Makefile,v 1.1.1.1 1999/01/18 03:51:18 steve Exp $

DISTNAME=	ezmlm-idx-${IDX_VERSION}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ezmlm.org/pub/patches/ \
		ftp://gd.tuwien.ac.at/infosys/mail/qmail/ezmlm-patches/ \
		ftp://ftp.win.or.jp/pub/network/mail/qmail/ezmlm-idx/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		ezmlm-${EZMLM_VERSION}${EXTRACT_SUFX}

MAINTAINER=	tom@eborcom.com

.if defined(NOPORTDOCS)
PLIST=		${PKGDIR}/PLIST.nodocs
.endif

# QMAIL_DIR is the directory where qmail is installed
.if !defined(QMAIL_DIR)
QMAIL_DIR=	/var/qmail
.endif

RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

NO_PACKAGE=	Unsure of djb's license

WRKSRC=		${WRKDIR}/ezmlm-${EZMLM_VERSION}

ALL_TARGET=	it

MAN1=		ezmlm-list.1 ezmlm-make.1 ezmlm-manage.1 ezmlm-reject.1 \
		ezmlm-return.1 ezmlm-send.1 ezmlm-sub.1 ezmlm-unsub.1 \
		ezmlm-warn.1 ezmlm-weed.1 ezmlm-accept.1 ezmlm-both.1 \
		ezmlm-issubn.1 ezmlm-glconf.1 ezmlm-glmake.1 ezmlm-moderate.1 \
		ezmlm-request.1 ezmlm-store.1 ezmlm-idx.1 ezmlm-gate.1 \
		ezmlm-tstdig.1 ezmlm-get.1 ezmlm-check.1 ezmlm-clean.1 \
		ezmlm-cron.1
MAN5=		ezmlm.5 ezmlmrc.5

DIFF_MSG=	Cannot Make and Install with different PREFIX or QMAIL_DIR

MY_PROGRAMS=	ezmlm-clean ezmlm-cron ezmlm-gate ezmlm-get ezmlm-idx \
		ezmlm-issubn ezmlm-list ezmlm-make ezmlm-manage \
		ezmlm-moderate ezmlm-request ezmlm-reject ezmlm-return \
		ezmlm-send ezmlm-store ezmlm-sub ezmlm-tstdig ezmlm-unsub \
		ezmlm-warn ezmlm-weed

MY_SCRIPTS=	ezmlm-accept ezmlm-both ezmlm-check ezmlm-glconf ezmlm-glmake

MY_CONFIG=	ezmlmrc

EZMLM_VERSION=	0.53
IDX_VERSION=	0.313

pre-patch:
	@${MV} -f ${WRKDIR}/ezmlm-idx-${IDX_VERSION}/* ${WRKSRC}
	@cd ${WRKSRC} && ${PATCH} < idx.patch

post-patch:
	@${ECHO} ${PREFIX}/bin > ${WRKSRC}/conf-bin
	@${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO} ${CC} -s > ${WRKSRC}/conf-ld
	@${ECHO} ${PREFIX}/man > ${WRKSRC}/conf-man
	@${ECHO} ${QMAIL_DIR} > ${WRKSRC}/conf-qmail
	@${ECHO} ${PREFIX} > ${WRKDIR}/.PPREFIX
	@${ECHO} ${QMAIL_DIR} >> ${WRKDIR}/.PPREFIX

pre-install:
	@${ECHO} ${PREFIX} > ${WRKDIR}/.IPREFIX
	@${ECHO} ${QMAIL_DIR} >> ${WRKDIR}/.IPREFIX
	@diff ${WRKDIR}/.[PI]PREFIX || (${ECHO} ${DIFF_MSG} && exit 1)

do-install:
.for file in ${MY_PROGRAMS}
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in ${MY_SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in ${MY_CONFIG}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/man/man1
.endfor
.for file in ${MAN5}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/man/man5
.endfor
.if !defined(NOPORTDOCS)
	@${ECHO} "===>  Copying documents to ${PREFIX}/share/doc/ezmlm-idx"
	@${MKDIR} ${PREFIX}/share/doc/ezmlm-idx
.for file in CHANGES.idx DOWNGRADE.idx FAQ.idx INSTALL.idx README.idx UPGRADE.idx
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/ezmlm-idx
.endfor
.endif

.include <bsd.port.mk>
