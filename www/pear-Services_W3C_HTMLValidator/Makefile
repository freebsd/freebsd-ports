# Ports collection makefile for:  pear-Services_W3C_HTMLValidator
# Date created:			  2007/04/29
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Services_W3C_HTMLValidator
PORTVERSION=	0.2.0
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An Object Oriented Interface to the W3C HTML Validator service.

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Services
FILES=		HTMLValidator.php HTMLValidator/Error.php HTMLValidator/Message.php \
		HTMLValidator/Response.php HTMLValidator/Warning.php
DOCS=		examples/example.html examples/validate_byfile.php  \
		examples/validate_byuri.php examples/validate_fragment.php \
		examples/validate_responsexml.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
