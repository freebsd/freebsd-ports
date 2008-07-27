# New ports collection makefile for:	serialmail
# Date created:		2 November 1998
# Whom:			Tom Hukins <tom@eborcom.com>
#
# $FreeBSD$
#

PORTNAME=	serialmail
PORTVERSION=	0.75
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/ \
		ftp://ftp.gbnet.net/pub/qmail/ \
		ftp://ftp.de.uu.net/pub/unix/mail/qmail/ \
		ftp://ftp.iway.fr/pub/unix/mail/qmail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for passing mail across serial links

RUN_DEPENDS=	tcpserver:${PORTSDIR}/sysutils/ucspi-tcp
USE_QMAIL_RUN=	yes

RESTRICTED=	Unsure of DJB license

ALL_TARGET=	it

OPTIONS=	AUTH "Add CRAM-MD5, PLAIN and LOGIN authentication" OFF \
		UCSPI_SSL "Add ucspi-ssl SMTP SSL transport layer support" OFF

PROGRAMS=	serialqmtp serialsmtp maildirserial setlock
SCRIPTS=	maildirqmtp maildirsmtp
MAN1=		maildirqmtp.1 maildirserial.1 maildirsmtp.1 serialqmtp.1 \
		serialsmtp.1 setlock.1
DOCS=		AUTOTURN BLURB CHANGES FROMISP README TODO TOISP THANKS

.include <bsd.port.pre.mk>

.if defined(WITH_AUTH)
PATCH_SITES=	http://www.ingorohloff.de/soft/
PATCHFILES=	serialmail-auth.patch
PATCH_DIST_STRIP=	-p1
.endif

.if defined(WITH_UCSPI_SSL)
RUN_DEPENDS+=	sslclient:${PORTSDIR}/sysutils/ucspi-ssl

PLIST_FILES+=	bin/maildirsmtps
MLINKS+=	maildirsmtp.1 maildirsmtps.1
.endif

post-patch:
.if defined(WITH_UCSPI_SSL)
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
		${INSTALL_PROGRAM} ${PROGRAMS} ${PREFIX}/bin && \
		${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin && \
		${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
.if defined(WITH_UCSPI_SSL)
	@${INSTALL_SCRIPT} ${WRKDIR}/maildirsmtps ${PREFIX}/bin
.endif

.include <bsd.port.post.mk>
