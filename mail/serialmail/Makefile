# Created by: Tom Hukins <tom@eborcom.com>
# $FreeBSD$

PORTNAME=	serialmail
PORTVERSION=	0.75
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/ \
		ftp://ftp.gbnet.net/pub/qmail/ \
		ftp://ftp.de.uu.net/pub/unix/mail/qmail/ \
		ftp://ftp.iway.fr/pub/unix/mail/qmail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for passing mail across serial links

RUN_DEPENDS=	tcpserver:sysutils/ucspi-tcp
UCSPI_SSL_RUN_DEPENDS=	sslclient:sysutils/ucspi-ssl

USES=		qmail:run
OPTIONS_SUB=	yes

LEGAL_TEXT=	No license -- see http://cr.yp.to/softwarelaw.html

ALL_TARGET=	it

OPTIONS_DEFINE=	AUTH DOCS UCSPI_SSL
AUTH_DESC=	Add CRAM-MD5, PLAIN and LOGIN authentication
UCSPI_SSL_DESC=	ucspi-ssl SMTP SSL transport layer support

PROGRAMS=	serialqmtp serialsmtp maildirserial setlock
SCRIPTS=	maildirqmtp maildirsmtp
MAN=		maildirqmtp.1 maildirserial.1 maildirsmtp.1 serialqmtp.1 \
		serialsmtp.1 setlock.1
PORTDOCS=	AUTOTURN BLURB CHANGES FROMISP README TODO TOISP THANKS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAUTH}
PATCH_SITES=	http://www.ingorohloff.de/soft/
PATCHFILES=	serialmail-auth.patch
PATCH_DIST_STRIP=	-p1
.endif

post-patch:
.if ${PORT_OPTIONS:MUCSPI_SSL}
	@${SED} -E \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%SH%%|${SH}|' \
		${FILESDIR}/maildirsmtps \
		> ${WRKDIR}/maildirsmtps
.endif

post-configure:
	@${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-home
	@${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s > ${WRKSRC}/conf-ld
	@${ECHO_CMD} ${QMAIL_PREFIX} > ${WRKSRC}/conf-qmail

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} ${PROGRAMS} ${STAGEDIR}${PREFIX}/bin && \
		${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${PREFIX}/bin && \
		${INSTALL_MAN} ${MAN} ${STAGEDIR}${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MUCSPI_SSL}
	@${INSTALL_SCRIPT} ${WRKDIR}/maildirsmtps ${STAGEDIR}${PREFIX}/bin
.endif

.include <bsd.port.mk>
