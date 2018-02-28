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

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Clone>=0:devel/p5-Clone \
		p5-XML-NamespaceSupport>=0:textproc/p5-XML-NamespaceSupport \
		p5-XML-SAX>=0:textproc/p5-XML-SAX
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
USE_PERL5=	configure
NO_ARCH=	yes
SHEBANG_GLOB=	*.pl

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	@${MKDIR} ${WRKSRC}/scripts
	@${MV} ${WRKSRC}/*.pl ${WRKSRC}/scripts

post-patch:
	@${REINPLACE_CMD} -e '/EXE_FILES/ s|\([[:alpha:]]*\.pl\)|scripts/&|g' ${WRKSRC}/Makefile.PL

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
