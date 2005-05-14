# New ports collection makefile for:	ucspi-tcp
# Date created:		12 June 1998
# Whom:			Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	ucspi-tcp
PORTVERSION=	0.88
PORTREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	http://cr.yp.to/ucspi-tcp/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dom@happygiraffe.net
COMMENT=	Command-line tools for building TCP client-server applications

.if !defined(WITHOUT_MAN)
MASTER_SITES+=	http://smarden.org/pape/djb/manpages/:1
DISTFILES+=	${DISTNAME}-man.tar.gz:1

OPTIONS=	RSS_DIFF "Patch rblsmtpd for qmail users" off

MAN1=		addcr.1 argv0.1 date@.1 delcr.1 finger@.1 fixcrio.1 \
		http@.1 mconnect.1 rblsmtpd.1 recordio.1 tcpcat.1 \
		tcpclient.1 tcprules.1 tcprulescheck.1 tcpserver.1 who@.1
.endif

NO_PACKAGE=	"Unsure of djb\'s license"

ALL_TARGET=	prog install instcheck

SCRIPTS_ENV=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" BINMODE="${BINMODE}" \
		MANMODE="${MANMODE}" CFLAGS="${CFLAGS}"

.include <bsd.port.pre.mk>

.if defined(WITH_RSS_DIFF)
PATCH_SITES=	http://www.qmail.org/
PATCHFILES=	ucspi-rss.diff
PATCH_DIST_STRIP=	-p1
.endif

post-configure:
	@${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-home
	@${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s > ${WRKSRC}/conf-ld

do-install:
.for file_name in addcr argv0 delcr fixcrio mconnect-io rblsmtpd recordio tcpclient tcprules tcprulescheck tcpserver
	@${INSTALL_PROGRAM} ${WRKSRC}/${file_name} ${PREFIX}/bin
.endfor
.for file_name in date@ finger@ http@ mconnect who@ tcpcat
	@${INSTALL_SCRIPT} ${WRKSRC}/${file_name} ${PREFIX}/bin
.endfor
.if !defined(WITHOUT_MAN)
	@cd ${WRKSRC}-man; ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1/
.endif

.include <bsd.port.post.mk>
