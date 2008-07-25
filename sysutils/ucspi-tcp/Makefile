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
MASTER_SITES=	http://cr.yp.to/ucspi-tcp/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	garga/ucspi-tcp

PATCH_DIST_STRIP=	-p1

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Command-line tools for building TCP client-server applications

OPTIONS=	MAN "Install man(1) pages" on \
		RSS_DIFF "Patch rblsmtpd for qmail users" off \
		SSL "Adds support for SSL (Secure Socket Layer)" off \
		RBL2SMTPD "Don't drop connection, pass envvar to smtpd" off

ALL_TARGET=	prog install instcheck

SCRIPTS_ENV=	BINOWN="${BINOWN}" \
		BINGRP="${BINGRP}" \
		BINMODE="${BINMODE}" \
		MANMODE="${MANMODE}" \
		CFLAGS="${CFLAGS}"

PROGRAMS=	addcr \
		argv0 \
		delcr \
		fixcrio \
		mconnect-io \
		rblsmtpd \
		recordio \
		tcpclient \
		tcprules \
		tcprulescheck \
		tcpserver

SCRIPTS=	date@ \
		finger@ \
		http@ \
		mconnect \
		who@ \
		tcpcat

.include <bsd.port.pre.mk>

# Restrict optimization to -O - -O2 causes problems at least on amd64
.if ${ARCH} == "amd64"
CFLAGS+=	-O
.endif

.if defined(WITH_MAN)
MASTER_SITES+=	http://smarden.org/pape/djb/manpages/:man \
		${MASTER_SITE_LOCAL:S/$/:man/}
MASTER_SITE_SUBDIR+=	garga/ucspi-tcp/:man
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-man.tar.gz:man
MAN1=		addcr.1 argv0.1 date@.1 delcr.1 finger@.1 fixcrio.1 \
		http@.1 mconnect.1 rblsmtpd.1 recordio.1 tcpcat.1 \
		tcpclient.1 tcprules.1 tcprulescheck.1 tcpserver.1 who@.1
.endif

.if defined(WITH_RSS_DIFF)
PATCH_SITES+=	http://www.qmail.org/:rss
PATCHFILES+=	ucspi-rss.diff:rss
.endif

.if defined(WITH_SSL)
# we can't use USE_OPENSSL=yes after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
PATCH_SITES+=	http://www.nrg4u.com/qmail/:ssl
PATCHFILES+=	ucspi-tcp-ssl-20050405.patch.gz:ssl
.endif

.if defined(WITH_RBL2SMTPD)
PATCHFILES+=	ucspi-tcp_rbl2smtpd.diff:rbl2smtpd
.endif

PATCH_SITES+=		${MASTER_SITE_LOCAL:S/$/:rss,ssl,rbl2smtpd/}
PATCH_SITE_SUBDIR+=	garga/ucspi-tcp/:rss,ssl,rbl2smtpd

post-patch:
.if defined(WITH_SSL)
	@${REINPLACE_CMD} -e 's|#INCS=-I/usr/local/include|INCS=-I${OPENSSLBASE}/include|g; \
			      s|-lcrypto|-L${OPENSSLBASE}/lib |g' \
		${WRKSRC}/Makefile
.endif

post-configure:
	@${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-home
	@${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s > ${WRKSRC}/conf-ld

do-install:
.for file_name in ${PROGRAMS}
	@${INSTALL_PROGRAM} ${WRKSRC}/${file_name} ${PREFIX}/bin
.endfor
.for file_name in ${SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/${file_name} ${PREFIX}/bin
.endfor
.if defined(WITH_MAN)
. for file_name in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}-man/${file_name} ${MAN1PREFIX}/man/man1/
. endfor
.endif

.include <bsd.port.post.mk>
