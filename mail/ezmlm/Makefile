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

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	An easy-to-use, high-speed mailing list manager for qmail

RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

CONFLICTS=	ezmlm-idx-*

NO_PACKAGE=	Unsure of DJB license

# QMAIL_DIR is the directory where qmail is installed
QMAIL_DIR?=	/var/qmail

ALL_TARGET=	it

PROGRAMS=	ezmlm-make ezmlm-manage ezmlm-send ezmlm-reject ezmlm-return \
		ezmlm-warn ezmlm-weed ezmlm-list ezmlm-sub ezmlm-unsub
MAN1=		ezmlm-list.1 ezmlm-make.1 ezmlm-manage.1 ezmlm-reject.1 \
		ezmlm-return.1 ezmlm-send.1 ezmlm-sub.1 ezmlm-unsub.1 \
		ezmlm-warn.1 ezmlm-weed.1
MAN5=		ezmlm.5
DOCS=		BLURB INSTALL README THANKS TODO

post-patch:
	@${ECHO_CMD} ${PREFIX}/bin > ${WRKSRC}/conf-bin
	@${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s > ${WRKSRC}/conf-ld
	@${ECHO_CMD} ${PREFIX}/man > ${WRKSRC}/conf-man
	@${ECHO_CMD} ${QMAIL_DIR} > ${WRKSRC}/conf-qmail

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} ${PROGRAMS} ${PREFIX}/bin && \
		${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1 && \
		${INSTALL_MAN} ${MAN5} ${MANPREFIX}/man/man5
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
