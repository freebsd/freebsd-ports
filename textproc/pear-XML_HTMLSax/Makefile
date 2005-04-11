# Ports collection makefile for:  pear-XML_HTMLSax
# Date created:			  31 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	XML_HTMLSax
PORTVERSION=	2.1.2
CATEGORIES=	textproc devel pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR SAX parser for HTML and other badly formed XML documents

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	XML
FILES=		XML_HTMLSax.php HTMLSax/XML_HTMLSax_States.php \
		HTMLSax/XML_HTMLSax_Decorators.php
DOCS=		Readme
EXAMPLES=	SimpleExample.php HTMLtoXHTML.php ExpatvsHtmlSax.php example.html
TESTS=		index.php unit_tests.php xml_htmlsax_test.php
_EXAMPLESDIR=	docs/examples
_TESTSDIR=	docs/tests

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
