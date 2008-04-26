# Ports collection makefile for:  pear-HTTP_Session
# Date created:			  13 December 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTTP_Session2
PORTVERSION=	0.7.2
CATEGORIES=	www devel pear

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	PHP5 Session Handler

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_DOS2UNIX=	yes

CATEGORY=	HTTP
FILES=		HTTP/Session2.php \
		HTTP/Session2/Container.php \
		HTTP/Session2/Exception.php \
		HTTP/Session2/Container/DB.php \
		HTTP/Session2/Container/Interface.php \
		HTTP/Session2/Container/MDB2.php \
		HTTP/Session2/Container/Memcache.php
EXAMPLES=	HTTP_Session2_Example.php sessiondata.sql
_EXAMPLESDIR=	docs
TESTS=		AllTests.php Session2Test.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
