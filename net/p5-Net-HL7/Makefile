PORTNAME=	Net-HL7
PORTVERSION=	0.76
CATEGORIES=	net perl5
MASTER_SITES=	SF/hl7toolkit/
PKGNAMEPREFIX=	p5-

MAINTAINER=	bbp2006@columbia.edu
COMMENT=	Simple yet flexible API for non-XML HL7 applications

LICENSE=	GPLv2

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
