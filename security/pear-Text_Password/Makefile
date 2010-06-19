# Ports collection makefile for:  pear-Text_Password
# Date created:			  29 March 2004
# Whom:				  Attila Nagy <bra@fsn.hu>
#
# $FreeBSD$
#

PORTNAME=	Text_password
PORTVERSION=	1.1.1
CATEGORIES=	security www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR random password creator

USE_PHP=	yes

CATEGORY=	Text
FILES=		Password.php
TESTS=		Text_Password_Test.php

WRKSRC=		${WRKDIR}/Text_Password-${PORTVERSION}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
