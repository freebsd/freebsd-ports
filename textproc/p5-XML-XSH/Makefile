# Created by: Lev Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTNAME=	XML-XSH
PORTVERSION=	1.8.2
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN/XML \
		SF/xsh/xsh/${PORTNAME}-${PORTVERSION}%20%28linux_unix%29
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	This is xsh - an XML Editing Shell

BUILD_DEPENDS=	p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-XML-LibXSLT>=0:textproc/p5-XML-LibXSLT \
		p5-XML-LibXML-Iterator>=0:textproc/p5-XML-LibXML-Iterator \
		p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent \
		p5-XML-XUpdate-LibXML>=0:textproc/p5-XML-XUpdate-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

test: build
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.mk>
