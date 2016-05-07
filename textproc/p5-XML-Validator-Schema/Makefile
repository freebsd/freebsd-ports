# Created by: clsung@dragon2.net
# $FreeBSD$

PORTNAME=	XML-Validator-Schema
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for validating XML documents against a W3C XML Schema

BUILD_DEPENDS=	p5-Tree-DAG_Node>=0:devel/p5-Tree-DAG_Node \
		p5-XML-SAX>=0:textproc/p5-XML-SAX \
		p5-XML-Filter-BufferText>=0:textproc/p5-XML-Filter-BufferText
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS

PORTDOCS=	ANNOUNCE Changes README TODO

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."

.include <bsd.port.mk>
