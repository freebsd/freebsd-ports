# Ports collection makefile for:  pear-Services_W3C_HTMLValidator
# Date created:			  2007/04/29
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Services_W3C_HTMLValidator
PORTVERSION=	1.0.0
PORTEPOCH=	1
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An Object Oriented Interface to the W3C HTML Validator service.

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request2.php:${PORTSDIR}/www/pear-HTTP_Request2
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request2.php:${PORTSDIR}/www/pear-HTTP_Request2

PEAR_CATSRC=	yes
CATEGORY=	Services
FILES=		W3C/HTMLValidator.php W3C/HTMLValidator/Error.php W3C/HTMLValidator/Message.php \
		W3C/HTMLValidator/Response.php W3C/HTMLValidator/Warning.php
_EXAMPLESDIR=	docs/examples
EXAMPLES=	example.html validate_byfile.php  \
		validate_byuri.php validate_fragment.php \
		validate_responsexml.php \
		PHPUnit/URIValidationTest.php PHPUnit/ValidationSuite.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
