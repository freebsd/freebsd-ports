# New ports collection makefile for:	serialmail
# Date created:		2 November 1998
# Whom:			Tom Hukins <tom@eborcom.com>
#
# $FreeBSD$
#

PORTNAME=	serialmail
PORTVERSION=	0.75
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/ \
		ftp://ftp.gbnet.net/pub/qmail/ \
		ftp://ftp.de.uu.net/pub/unix/mail/qmail/ \
		ftp://ftp.iway.fr/pub/unix/mail/qmail/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Tools for passing mail across serial links

RUN_DEPENDS=	tcpserver:${PORTSDIR}/sysutils/ucspi-tcp \
		${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

# QMAIL_DIR is the directory where qmail is installed
QMAIL_DIR?=	/var/qmail

NO_PACKAGE=	Unsure of DJB license

ALL_TARGET=	it

PROGRAMS=	serialqmtp serialsmtp maildirserial setlock
SCRIPTS=	maildirqmtp maildirsmtp
MAN1=		maildirqmtp.1 maildirserial.1 maildirsmtp.1 serialqmtp.1 \
		serialsmtp.1 setlock.1
DOCS=		AUTOTURN BLURB CHANGES FROMISP README TODO TOISP THANKS

post-configure:
	@${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-home
	@${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s > ${WRKSRC}/conf-ld
	@${ECHO_CMD} ${QMAIL_DIR} > ${WRKSRC}/conf-qmail

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} ${PROGRAMS} ${PREFIX}/bin && \
		${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin && \
		${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
