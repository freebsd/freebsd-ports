# New ports collection makefile for:	ezmlm
# Date created:		28 November 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$
#

PORTNAME=	ezmlm
PORTVERSION=	0.53
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/ \
		ftp://ftp.fu-berlin.de/unix/mail/qmail/ \
		ftp://ftp.st.ryukoku.ac.jp/pub/network/mail/qmail/ \
		ftp://ftp.gbnet.net/pub/qmail/ \
		ftp://ftp.iway.fr/pub/unix/mail/qmail/ \
		ftp://ftp.nl.uu.net/pub/unix/mail/qmail/ \
		ftp://ftp.archive.de.uu.net/pub/unix/mail/qmail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An easy-to-use, high-speed mailing list manager for qmail

# QMAIL_DIR is the directory where qmail is installed
.if !defined(QMAIL_DIR)
QMAIL_DIR=	/var/qmail
.endif

RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

NO_PACKAGE=	Unsure of djb's license

ALL_TARGET=	it

MAN1=		ezmlm-list.1 ezmlm-make.1 ezmlm-manage.1 ezmlm-reject.1 \
		ezmlm-return.1 ezmlm-send.1 ezmlm-sub.1 ezmlm-unsub.1 \
		ezmlm-warn.1 ezmlm-weed.1
MAN5=		ezmlm.5

DIFF_MSG=	Cannot Make and Install with different PREFIX or QMAIL_DIR

MY_PROGRAMS=	ezmlm-make ezmlm-manage ezmlm-send ezmlm-reject ezmlm-return \
		ezmlm-warn ezmlm-weed ezmlm-list ezmlm-sub ezmlm-unsub

post-patch:
	@${ECHO_CMD} ${PREFIX}/bin > ${WRKSRC}/conf-bin
	@${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s > ${WRKSRC}/conf-ld
	@${ECHO_CMD} ${PREFIX}/man > ${WRKSRC}/conf-man
	@${ECHO_CMD} ${QMAIL_DIR} > ${WRKSRC}/conf-qmail
	@${ECHO_CMD} ${PREFIX} > ${WRKDIR}/.PPREFIX
	@${ECHO_CMD} ${QMAIL_DIR} >> ${WRKDIR}/.PPREFIX

pre-install:
	@${ECHO_CMD} ${PREFIX} > ${WRKDIR}/.IPREFIX
	@${ECHO_CMD} ${QMAIL_DIR} >> ${WRKDIR}/.IPREFIX
	@diff ${WRKDIR}/.[PI]PREFIX || (${ECHO} ${DIFF_MSG} && exit 1)

do-install:
.for file in ${MY_PROGRAMS}
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/man/man1
.endfor
.for file in ${MAN5}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/man/man5
.endfor

.include <bsd.port.mk>
