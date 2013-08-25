# Created by: adam
# $FreeBSD$

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

OPTIONS_SET=	DOCS EXAMPLES

INSTALL_TARGET=	install-suid install.man
MAKE_JOBS_UNSAFE=	yes

MAN1=		formail.1 lockfile.1 procmail.1
MAN5=		procmailex.5 procmailrc.5 procmailsc.5
PLIST_FILES=	bin/formail bin/lockfile bin/mailstat bin/procmail
PORTDOCS=	FAQ FEATURES HISTORY KNOWN_BUGS README
PORTEXAMPLES=	1procmailrc 1rmail 2procmailrc 2rmail 3procmailrc 3rmail \
		advanced dirname forward local_procmail_lmtp.m4 mailstat

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/config.h

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	cd ${WRKSRC}/examples/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
