# Ports collection makefile for:  pear-Text_Password
# Date created:			  29 March 2004
# Whom:				  Attila Nagy <bra@fsn.hu>
#
# $FreeBSD$
#

PORTNAME=	Text_password
PORTVERSION=	1.1.0
CATEGORIES=	security www pear

MAINTAINER=	jmelo@FreeBSD.org
COMMENT=	PEAR random password creator

USE_PHP=	yes
WANT_PHP_PEAR=	yes

CATEGORY=	Text
FILES=		Password.php
TESTS=		Text_Password_Test.php

WRKSRC=		${WRKDIR}/Text_Password-${PORTVERSION}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
