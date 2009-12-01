# Ports collection makefile for:  pear-HTTP
# Date created:			  13 December 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTTP
PORTVERSION=	1.4.1
CATEGORIES=	www devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR miscellaneous HTTP utilities

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		HTTP.php

TESTS=		absoluteURI.inc negotiateCharset.phpt negotiateCharset2.phpt \
		negotiateLanguage.phpt negotiateMimeType.phpt test1a.phpt \
		test2a.phpt test3a.phpt test4a.phpt test5a.phpt test6a.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
