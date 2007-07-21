# Ports collection makefile for:  pear-HTTP_Session
# Date created:			  13 December 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTTP_Session
PORTVERSION=	0.5.6
CATEGORIES=	www devel pear

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	PEAR Object-oriented interface to the session_* family functions

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_DOS2UNIX=	yes

FILES=		Session.php Session/Container.php Session/Container/DB.php \
		Session/Container/MDB.php Session/Container/MDB2.php \
		Session/Container/Memcache.php
EXAMPLES=	HTTP_Session_Example.php Container_Example.php sessiondata.sql
_EXAMPLESDIR=	docs
TESTS=		AllTests.bat AllTests.php HTTP_SessionTest.php \
		HTTP_Session_ContainerTest.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
