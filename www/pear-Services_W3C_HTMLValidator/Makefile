# Ports collection makefile for:  pear-Services_W3C_HTMLValidator
# Date created:			  2007/04/29
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Services_W3C_HTMLValidator
DISTVERSION=	1.0.0RC2
PORTREVISION=	2
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An Object Oriented Interface to the W3C HTML Validator service.

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request2.php:${PORTSDIR}/www/pear-HTTP_Request2
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request2.php:${PORTSDIR}/www/pear-HTTP_Request2

CATEGORY=	Services
FILES=		HTMLValidator.php HTMLValidator/Error.php HTMLValidator/Message.php \
		HTMLValidator/Response.php HTMLValidator/Warning.php
_EXAMPLESDIR=	docs/examples
EXAMPLES=	example.html validate_byfile.php  \
		validate_byuri.php validate_fragment.php \
		validate_responsexml.php \
		PHPUnit/URIValidationTest.php PHPUnit/ValidationSuite.php


.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
