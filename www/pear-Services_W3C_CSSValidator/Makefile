# Ports collection makefile for:  pear-Services_W3C_CSSValidator:
# Date created:			  21 Jan 2007
# Whom:				  Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	Services_W3C_CSSValidator
PORTVERSION=	0.2.2
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP interface to W3C CSS Validator API

BUILD_DEPENDS=	${PEARDIR}/HTTP/Request2.php:${PORTSDIR}/www/pear-HTTP_Request2
RUN_DEPENDS=	${PEARDIR}/HTTP/Request2.php:${PORTSDIR}/www/pear-HTTP_Request2

PEAR_CATSRC=	yes

CATEGORY=	Services
FILES=		W3C/CSSValidator.php W3C/CSSValidator/Error.php W3C/CSSValidator/Message.php \
		W3C/CSSValidator/Response.php W3C/CSSValidator/Warning.php
TESTS=		AllTests.php fragment.css Services_W3C_CSSValidatorTest.php
EXAMPLES=	examples/foo.css examples/fragment.css examples/pear_manual.css \
		examples/validate_atrules.php examples/validate_byfile.php \
		examples/validate_byuri.php examples/validate_fragment.php
_EXAMPLESDIR=	docs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
