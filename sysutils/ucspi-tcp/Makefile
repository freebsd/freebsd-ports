# New ports collection makefile for:	ucspi-tcp
# Version required:     0.84
# Date created:		12 June 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $FreeBSD$
#

DISTNAME=	ucspi-tcp-0.84
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://koobera.math.uic.edu/www/software/

MAINTAINER=     dom@myrddin.demon.co.uk

MAN1=		tcpclient.1 tcpserver.1 tcprules.1 tcprulescheck.1 \
		fixcr.1 addcr.1 delcr.1 who@.1 date@.1 finger@.1 http@.1 \
		tcpcat.1 mconnect.1 argv0.1 recordio.1
MAN5=		tcp-environ.5

.if defined(NOPORTDOCS)
PLIST=		${PKGDIR}/PLIST.nodocs
.endif

NO_PACKAGE=	Unsure of djb's license

ALL_TARGET=	prog install instcheck

SCRIPTS_ENV=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" BINMODE="${BINMODE}" \
		MANMODE="${MANMODE}" CFLAGS="${CFLAGS}"

post-configure:
	@${ECHO} ${PREFIX} > ${WRKSRC}/conf-home
	@${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO} ${CC} -s > ${WRKSRC}/conf-ld

do-install:
.for file in addcr argv0 delcr fixcr mconnect-io recordio tcpclient tcprules tcprulescheck tcpserver
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in date@ finger@ http@ mconnect who@ tcpcat
	@${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/man/man1
.endfor
.for file in ${MAN5}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/man/man5
.endfor
.if !defined(NOPORTDOCS)
	@${ECHO} "===>  Copying documents to ${PREFIX}/share/doc/ucspi-tcp"
	@${MKDIR} ${PREFIX}/share/doc/ucspi-tcp
.for file in BLURB TCP UCSPI
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/ucspi-tcp
.endfor
.endif

.include <bsd.port.mk>
