# New ports collection makefile for:	ucspi-tcp
# Date created:		12 June 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $FreeBSD$
#

PORTNAME=	ucspi-tcp
PORTVERSION=	0.88
CATEGORIES=	sysutils net
MASTER_SITES=	http://cr.yp.to/ucspi-tcp/

MAINTAINER=	dom@myrddin.demon.co.uk

NO_PACKAGE=	"Unsure of djb\'s license"

ALL_TARGET=	prog install instcheck

SCRIPTS_ENV=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" BINMODE="${BINMODE}" \
		MANMODE="${MANMODE}" CFLAGS="${CFLAGS}"

post-configure:
	@${ECHO} ${PREFIX} > ${WRKSRC}/conf-home
	@${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO} ${CC} -s > ${WRKSRC}/conf-ld

do-install:
.for file in addcr argv0 delcr fixcrio mconnect-io rblsmtpd recordio tcpclient tcprules tcprulescheck tcpserver
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in date@ finger@ http@ mconnect who@ tcpcat
	@${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
