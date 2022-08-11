PORTNAME=	File-Scan
PORTVERSION=	1.43
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jims@bluenotch.com
COMMENT=	Perl5 anti-virus file scanning package

USES=		perl5 shebangfix
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

SHEBANG_FILES=	examples/*.pl examples/procmail/scanvirus.pl

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/docs
.for file in Changes FAQ README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.for f in docs/write_sign_bin.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/docs
.endfor

	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/procmail
.for f in latest.pl scan.pl
	${INSTALL_SCRIPT} ${WRKSRC}/examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.for f in procmail/.procmailrc procmail/README procmail/scanvirus.pl
	${INSTALL_SCRIPT} ${WRKSRC}/examples/${f} \
		${STAGEDIR}${EXAMPLESDIR}/procmail
.endfor

.include <bsd.port.mk>
