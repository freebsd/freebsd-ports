# Ports collection makefile for:  pear-Text_Password
# Date created:			  29 March 2004
# Whom:				  Attila Nagy <bra@fsn.hu>
#
# $FreeBSD$
#

PORTNAME=	Text_password
PORTVERSION=	1.0
CATEGORIES=	security www pear

MAINTAINER=	bra@fsn.hu
COMMENT=	PEAR random password creator

BROKEN=		Incomplete pkg-plist

USE_PHP=	yes
WANT_PHP_PEAR=	yes

CATEGORY=	Text
FILES=		Password.php
TESTS=		01-text-password.phpt

WRKSRC=		${WRKDIR}/Text_Password-${PORTVERSION}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
