# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-STX
PORTVERSION=	0.43
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pure Perl STX processor

BUILD_DEPENDS=	p5-XML-SAX>=0:textproc/p5-XML-SAX \
		p5-Clone>=0:devel/p5-Clone \
		p5-XML-NamespaceSupport>=0:textproc/p5-XML-NamespaceSupport
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	examples/tester.pl examples/stx-filter.pl
USE_PERL5=	configure patch
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	@${MKDIR} ${WRKSRC}/scripts
	@${MV} ${WRKSRC}/stx*.pl ${WRKSRC}/scripts

post-patch:
	@${PERL} -pi -e 's!(?=stx\w+\.pl)!scripts/!g' ${WRKSRC}/Makefile.PL

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
