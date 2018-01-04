# Created by: Adam David <adam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	procmail
PORTVERSION=	3.22
PORTREVISION=	10
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

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS EXAMPLES

INSTALL_TARGET=	install.bin install.man
USES=		cpe
EXTRA_PATCHES=	${FILESDIR}/procmail-3.22-getline.patch:-p1

PORTDOCS=	FAQ FEATURES HISTORY KNOWN_BUGS README
PORTEXAMPLES=	1procmailrc 1rmail 2procmailrc 2rmail 3procmailrc 3rmail \
		advanced dirname forward local_procmail_lmtp.m4 mailstat

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/config.h ${WRKSRC}/src/autoconf
# Allow parallel builds (-jX) to work
	@${FIND} ${WRKSRC} -name 'Makefile*' | ${XARGS} ${REINPLACE_CMD} -E 's|cd (.+); (\$$\(MAKE\))|\2 -C \1|'

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/examples/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
