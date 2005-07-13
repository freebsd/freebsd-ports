# New ports collection makefile for:	anomy-sanitizer
# Date created:		2003-02-11
# Whom:			janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	anomy-sanitizer
PORTVERSION=	1.71
CATEGORIES=	mail security
MASTER_SITES=	http://mailtools.anomy.net/dist/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Sanitize and clean incoming/outgoing mail

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		procmail:${PORTSDIR}/mail/procmail

USE_PERL5=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/anomy

DOCS=		CHANGELOG.sanitizer CREDITS README.sanitizer sanitizer.html

do-install:
	@${MKDIR} ${SITE_PERL}/Anomy/Sanitizer/
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/HTMLCleaner.pm ${SITE_PERL}/Anomy
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Log.pm ${SITE_PERL}/Anomy
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/MIMEStream.pm ${SITE_PERL}/Anomy
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Sanitizer.pm ${SITE_PERL}/Anomy
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Sanitizer/FProt.pm ${SITE_PERL}/Anomy/Sanitizer/
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Sanitizer/MacroScanner.pm ${SITE_PERL}/Anomy/Sanitizer/
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Sanitizer/Scoring.pm ${SITE_PERL}/Anomy/Sanitizer/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sanitizer.pl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/simplify.pl ${PREFIX}/bin

post-install:
	${INSTALL_DATA} ${FILESDIR}/sanitizer.cfg.sample ${PREFIX}/etc/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Sample config installed at ${PREFIX}/etc/sanitizer.cfg.sample"
	@${ECHO_MSG} ""
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
