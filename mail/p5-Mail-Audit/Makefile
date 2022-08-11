PORTNAME=	Mail-Audit
PORTVERSION=	2.228
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for creating easy mail filters

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-HomeDir>=0.61:devel/p5-File-HomeDir \
		p5-File-Tempdir>=0:devel/p5-File-Tempdir \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools \
		p5-Mail-Tools>=0:mail/p5-Mail-Tools
TEST_DEPENDS=	p5-Mail-POP3Client>=0:mail/p5-Mail-POP3Client \
		p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/*
USE_PERL5=	configure
NO_ARCH=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	Changes FAQ README
PORTEXAMPLES=	popread proc2ma

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/var/spool/mail|/var/mail|g' \
		${WRKSRC}/lib/Mail/Audit.pm

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/${i}
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${PORTEXAMPLES}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${i}  ${STAGEDIR}${EXAMPLESDIR}/${i}
.endfor

.include <bsd.port.mk>
