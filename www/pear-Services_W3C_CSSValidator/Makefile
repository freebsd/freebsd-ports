# Ports collection makefile for:  pear-Services_W3C_CSSValidator:
# Date created:			  21 Jan 2007
# Whom:				  Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	Services_W3C_CSSValidator
PORTVERSION=	0.1.0
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP interface to W3C CSS Validator API

BUILD_DEPENDS=	${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
RUN_DEPENDS=	${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request

CATEGORY=	Services

FILES=		CSSValidator.php CSSValidator/Error.php CSSValidator/Message.php \
		CSSValidator/Response.php CSSValidator/Warning.php
TESTS=		AllTests.php fragment.css Services_W3C_CSSValidatorTest.php
EXAMPLES=	examples/foo.css examples/fragment.css examples/pear_manual.css \
		examples/validate_atrules.php examples/validate_byfile.php \
		examples/validate_byuri.php examples/validate_fragment.php
_EXAMPLESDIR=	docs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
