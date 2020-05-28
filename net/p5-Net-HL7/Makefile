# Created by: Brent B. Powers <bbp2006@columbia.edu>
# $FreeBSD$

PORTNAME=	Net-HL7
PORTVERSION=	0.75
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	SF/hl7toolkit/hl7api/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	bbp2006@columbia.edu
COMMENT=	Simple yet flexible API for non-XML HL7 applications

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
