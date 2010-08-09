# Ports collection makefile for:  pear-HTTP_Session
# Date created:			  13 December 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTTP_Session2
PORTVERSION=	0.7.3
CATEGORIES=	www devel pear

MAINTAINER=	joehorn@gmail.com
COMMENT=	PHP5 Session Handler

LICENSE=	BSD

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_DOS2UNIX=	yes

IGNORE_WITH_PHP=	4

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
TESTS=		AllTests.php functions.php \
		test-session2.phpt test-session-doctrine.phpt \
		test-session-mdb2.phpt test-session.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
