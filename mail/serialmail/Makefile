# New ports collection makefile for:	serialmail
# Version required:	0.75
# Date created:		2 November 1998
# Whom:			Tom Hukins <tom@eborcom.com>
#
# $Id$
#

DISTNAME=	serialmail-0.75
CATEGORIES=	mail
MASTER_SITES=	ftp://koobera.math.uic.edu/pub/software/

MAINTAINER=	tom@eborcom.com

MAN1=		maildirqmtp.1 maildirserial.1 maildirsmtp.1 serialqmtp.1 serialsmtp.1 setlock.1

.if defined(NOPORTDOCS)
PLIST=		${PKGDIR}/PLIST.nodocs
.endif

# QMAIL_DIR is the directory where qmail is installed
.if !defined(QMAIL_DIR)
QMAIL_DIR=	/var/qmail
.endif

RUN_DEPENDS=	${PREFIX}/bin/tcpserver:${PORTSDIR}/sysutils/ucspi-tcp \
		${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

NO_PACKAGE=	Unsure of djb's license

ALL_TARGET=	it

post-configure:
	@${ECHO} ${PREFIX} > ${WRKSRC}/conf-home
	@${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO} ${CC} -s > ${WRKSRC}/conf-ld
	@${ECHO} ${QMAIL_DIR} > ${WRKSRC}/conf-qmail

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
