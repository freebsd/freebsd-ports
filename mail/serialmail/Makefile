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

MAINTAINER=	tom@FreeBSD.org

MAN1=		maildirqmtp.1 maildirserial.1 maildirsmtp.1 serialqmtp.1 serialsmtp.1 setlock.1

# QMAIL_DIR is the directory where qmail is installed
QMAIL_DIR?=	/var/qmail

RUN_DEPENDS=	${PREFIX}/bin/tcpserver:${PORTSDIR}/sysutils/ucspi-tcp \
		${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

NO_PACKAGE=	Unsure of djb's license

ALL_TARGET=	it

post-configure:
	@${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-home
	@${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s > ${WRKSRC}/conf-ld
	@${ECHO_CMD} ${QMAIL_DIR} > ${WRKSRC}/conf-qmail

do-install:
.for file in serialqmtp serialsmtp maildirserial setlock
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in maildirqmtp maildirsmtp
	@${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in maildirqmtp.1 maildirserial.1 maildirsmtp.1 serialqmtp.1 serialsmtp.1 setlock.1
	@${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${ECHO} "===>  Copying documents to ${PREFIX}/share/doc/serialmail"
	@${MKDIR} ${PREFIX}/share/doc/serialmail
.for file in FROMISP TOISP AUTOTURN
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/serialmail
.endfor
.endif

.include <bsd.port.mk>
