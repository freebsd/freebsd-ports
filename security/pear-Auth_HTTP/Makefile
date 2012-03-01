# Ports collection makefile for:	pear-Auth_HTTP
# Date created:				2004-10-25
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	Auth_HTTP
PORTVERSION=	2.1.8
CATEGORIES=	security www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR HTTP authentication

BUILD_DEPENDS=	${PEARDIR}/Auth/Auth.php:${PORTSDIR}/security/pear-Auth
RUN_DEPENDS:=	${BUILD_DEPENDS}

CATEGORY=	Auth
PEAR_CATSRC=	yes
FILES=		HTTP.php
TESTS=		sample.sql test_basic_simple.php test_digest_simple.php \
		test_digest_get.php test_digest_post.php
_TESTSDIR=	docs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
