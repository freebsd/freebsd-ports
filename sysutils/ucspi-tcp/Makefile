# Created by: Dom Mitchell <dom@happygiraffe.net>

PORTNAME=	ucspi-tcp
PORTVERSION=	0.88
PORTREVISION=	2
CATEGORIES=	sysutils net
MASTER_SITES=	http://cr.yp.to/ucspi-tcp/ \
		LOCAL/garga/ucspi-tcp

PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line tools for building TCP client-server applications

CONFLICTS_INSTALL=	freedt # bin/argv0

OPTIONS_DEFINE=	RSS_DIFF RBL2SMTPD IPV6 SSL LIMITS

RSS_DIFF_DESC=	Patch rblsmtpd for qmail users
RBL2SMTPD_DESC=	Don't drop connection, pass envvar to smtpd
LIMITS_DESC=	Implement per-connection and other limits

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

.include <bsd.port.options.mk>

# SSL and LIMITS can't coexist
.if ${PORT_OPTIONS:MSSL} && ${PORT_OPTIONS:MLIMITS}
BROKEN=	SSL and LIMITS options cannot coexist, please choose one of them
.endif

MASTER_SITES+=	http://smarden.org/pape/djb/manpages/:man \
		LOCAL/garga/ucspi-tcp/:man
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-man.tar.gz:man
MAN_FILES=	addcr.1 argv0.1 date@.1 delcr.1 finger@.1 fixcrio.1 \
		http@.1 mconnect.1 rblsmtpd.1 recordio.1 tcpcat.1 \
		tcpclient.1 tcprules.1 tcprulescheck.1 tcpserver.1 who@.1

.if ${PORT_OPTIONS:MRSS_DIFF}
PATCH_SITES+=	http://www.qmail.org/:rss
PATCHFILES+=	ucspi-rss.diff:rss
.endif

.if ${PORT_OPTIONS:MSSL}
USES+=		ssl
PATCH_SITES+=	http://www.nrg4u.com/qmail/:ssl
PATCHFILES+=	ucspi-tcp-ssl-20050405.patch.gz:ssl
.endif

.if ${PORT_OPTIONS:MRBL2SMTPD}
PATCHFILES+=	ucspi-tcp_rbl2smtpd.diff:rbl2smtpd
.endif

.if ${PORT_OPTIONS:MLIMITS}
PATCH_SITES+=	http://linux.voyager.hr/ucspi-tcp/files/:limits
PATCHFILES+=	tcpserver-limits-2006-01-26.diff:limits
.endif

.if ${PORT_OPTIONS:MIPV6}
# Neither can IPv6 and SSL
. if ${PORT_OPTIONS:MSSL}
BROKEN=	SSL and IPv6 options cannot coexist, please choose one of them
. endif

# Same for IPv6 and LIMITS
. if ${PORT_OPTIONS:MLIMITS}
BROKEN=	IPv6 and LIMITS options cannot coexist, please choose one of them
. endif

PATCH_SITES+=	http://www.fefe.de/ucspi/:ipv6
PATCHFILES+=	ucspi-tcp-0.88-ipv6.diff19.bz2:ipv6
.endif

PATCH_SITES+=		LOCAL/garga/ucspi-tcp/:rss,ssl,rbl2smtpd

.include <bsd.port.pre.mk>

# Restrict optimization to -O - -O2 causes problems at least on amd64
.if ${ARCH} == "amd64"
CFLAGS+=	-O
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/^extern int errno;/#include <errno.h>/' \
		${WRKSRC}/error.h
.if ${PORT_OPTIONS:MSSL}
	@${REINPLACE_CMD} -e 's|#INCS=-I/usr/local/include|INCS=-I${OPENSSLINC}|g; \
			      /^LIBS=/s|-lcrypto|-L${OPENSSLLIB} &|g' \
		${WRKSRC}/Makefile
.endif

post-configure:
	@${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-home
	@${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s > ${WRKSRC}/conf-ld

do-install:
.for file_name in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${file_name} ${STAGEDIR}${PREFIX}/bin
.endfor
.for file_name in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${file_name} ${STAGEDIR}${PREFIX}/bin
.endfor
.for file_name in ${MAN_FILES}
	${INSTALL_MAN} ${WRKSRC}-man/${file_name} ${STAGEDIR}${MAN1PREFIX}/man/man1/
.endfor

.include <bsd.port.post.mk>
