# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	anomy-sanitizer
PORTVERSION=	1.76
PORTREVISION=	5
CATEGORIES=	mail security
MASTER_SITES=	http://mailtools.anomy.net/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sanitize and clean incoming/outgoing mail

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/sanitizer.pl bin/simplify.pl
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/anomy
DOCS=		CHANGELOG.sanitizer CREDITS README.sanitizer sanitizer.html
OPTIONS_DEFINE= DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${SITE_PERL}/Anomy/Sanitizer/
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/HTMLCleaner.pm ${STAGEDIR}${SITE_PERL}/Anomy
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Log.pm ${STAGEDIR}${SITE_PERL}/Anomy
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/MIMEStream.pm ${STAGEDIR}${SITE_PERL}/Anomy
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Sanitizer.pm ${STAGEDIR}${SITE_PERL}/Anomy
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Sanitizer/FProt.pm ${STAGEDIR}${SITE_PERL}/Anomy/Sanitizer/
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Sanitizer/FileTypes.pm ${STAGEDIR}${SITE_PERL}/Anomy/Sanitizer/
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Sanitizer/MacroScanner.pm ${STAGEDIR}${SITE_PERL}/Anomy/Sanitizer/
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Sanitizer/Scoring.pm ${STAGEDIR}${SITE_PERL}/Anomy/Sanitizer/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sanitizer.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/simplify.pl ${STAGEDIR}${PREFIX}/bin

post-install:
	${INSTALL_DATA} ${FILESDIR}/sanitizer.cfg.sample ${STAGEDIR}${PREFIX}/etc/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Sample config installed at ${PREFIX}/etc/sanitizer.cfg.sample"
	@${ECHO_MSG} ""
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
