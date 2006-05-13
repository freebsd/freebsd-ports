# New ports collection makefile for:	ucspi-tcp
# Date created:		12 June 1998
# Whom:			Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	ucspi-tcp
PORTVERSION=	0.88
PORTREVISION=	2
CATEGORIES=	sysutils net
MASTER_SITES=	http://cr.yp.to/ucspi-tcp/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dom@happygiraffe.net
COMMENT=	Command-line tools for building TCP client-server applications

OPTIONS=	MAN "Install man(1) pages" on \
		RSS_DIFF "Patch rblsmtpd for qmail users" off \
		SSL "Adds support for SSL (Secure Socket Layer)" off

NO_PACKAGE=	"Unsure of djb\'s license"

ALL_TARGET=	prog install instcheck

SCRIPTS_ENV=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" BINMODE="${BINMODE}" \
		MANMODE="${MANMODE}" CFLAGS="${CFLAGS}"

.if defined(WITH_SSL)
USE_OPENSSL=	yes
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MAN)
MASTER_SITES+=	http://smarden.org/pape/djb/manpages/:1
DISTFILES+=	${DISTNAME}-man.tar.gz:1
MAN1=		addcr.1 argv0.1 date@.1 delcr.1 finger@.1 fixcrio.1 \
		http@.1 mconnect.1 rblsmtpd.1 recordio.1 tcpcat.1 \
		tcpclient.1 tcprules.1 tcprulescheck.1 tcpserver.1 who@.1
.endif

.if defined(WITH_RSS_DIFF)
PATCH_SITES+=	http://www.qmail.org/
PATCHFILES+=	ucspi-rss.diff
PATCH_DIST_STRIP=	-p1
.endif

.if defined(WITH_SSL)
PATCH_SITES+=	http://www.nrg4u.com/qmail/
PATCHFILES+=	ucspi-tcp-ssl-20050405.patch.gz
PATCH_DIST_STRIP=	-p1

post-patch:
	@${REINPLACE_CMD} -e 's|#INCS=-I/usr/local/include|INCS=-I${OPENSSLBASE}/include|g; \
			s|-lcrypto|-L${OPENSSLBASE}/lib |g' ${WRKSRC}/Makefile
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
