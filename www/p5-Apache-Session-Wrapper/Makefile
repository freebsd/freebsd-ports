# Created by: mat
# $FreeBSD$

PORTNAME=	Apache-Session-Wrapper
PORTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple wrapper around Apache::Session

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Container>=0:devel/p5-Class-Container \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Exception-Class>=0:devel/p5-Exception-Class \
		p5-Apache-Session>=0:www/p5-Apache-Session

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	Changes

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."

.include <bsd.port.mk>
