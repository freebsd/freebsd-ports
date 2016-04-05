# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	anomy-sanitizer
PORTVERSION=	1.76
PORTREVISION=	6
CATEGORIES=	mail security
MASTER_SITES=	http://mailtools.anomy.net/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sanitize and clean incoming/outgoing mail

LICENSE=	GPLv2+

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/sanitizer.pl bin/simplify.pl
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/anomy

PORTDOCS=	CHANGELOG.sanitizer CREDITS README.sanitizer sanitizer.html UNICODE.TXT

OPTIONS_DEFINE= DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Anomy/Sanitizer/
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/HTMLCleaner.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Anomy
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Log.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Anomy
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/MIMEStream.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Anomy
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Sanitizer.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Anomy
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Sanitizer/FProt.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Anomy/Sanitizer/
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Sanitizer/FileTypes.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Anomy/Sanitizer/
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Sanitizer/MacroScanner.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Anomy/Sanitizer/
	${INSTALL_DATA} ${WRKSRC}/bin/Anomy/Sanitizer/Scoring.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Anomy/Sanitizer/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sanitizer.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/simplify.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/sanitizer.cfg.sample ${STAGEDIR}${PREFIX}/etc/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
