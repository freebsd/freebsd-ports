# New ports collection makefile for:	procmail
# Date created:		24 September 1994
# Whom:			adam
#
# $FreeBSD$
#

PORTNAME=	procmail
PORTVERSION=	3.22
PORTREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ucsb.edu/pub/mirrors/procmail/ \
		ftp://ftp.informatik.rwth-aachen.de/pub/packages/procmail/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/procmail/ \
		ftp://ftp.kfki.hu/pub/packages/mail/procmail/ \
		http://www.ring.gr.jp/archives/net/mail/procmail/ \
		ftp://ftp.ring.gr.jp/pub/net/mail/procmail/ \
		ftp://ftp.mirrorservice.org/sites/ftp.procmail.org/pub/procmail/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Local mail delivery agent

INSTALL_TARGET=	install-suid install.man
MAKE_JOBS_UNSAFE=	yes

DOCS=		FAQ FEATURES HISTORY KNOWN_BUGS README
EXAMPLES=	1procmailrc 1rmail 2procmailrc 2rmail 3procmailrc 3rmail \
		advanced dirname forward local_procmail_lmtp.m4 mailstat
MAN1=		formail.1 lockfile.1 procmail.1
MAN5=		procmailex.5 procmailrc.5 procmailsc.5

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/config.h

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	cd ${WRKSRC}/examples/ && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
