# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	anomy-sanitizer
PORTVERSION=	1.76
PORTREVISION=	4
CATEGORIES=	mail security
MASTER_SITES=	http://mailtools.anomy.net/dist/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Sanitize and clean incoming/outgoing mail

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
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Sanitizer/FileTypes.pm ${SITE_PERL}/Anomy/Sanitizer/
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
