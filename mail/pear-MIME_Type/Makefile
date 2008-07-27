# Ports collection makefile for:  pear-MIME_Type
# Date created:			  18 April 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	MIME_Type
PORTVERSION=	1.1.1
CATEGORIES=	mail www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class for dealing with MIME types

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-${PORTNAME}
OPTIONS=	PEAR_SYSTEM_COMMAND "PEAR::System_Command support" off

CATEGORY=	MIME
FILES=		MIME/Type.php MIME/Type/Parameter.php
EXAMPLES=	example.php
_EXAMPLESDIR=	docs/examples/
TESTS=		TypeTest.php

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_SYSTEM_COMMAND)
RUN_DEPENDS+=	${PEARDIR}/System/Command.php:${PORTSDIR}/devel/pear-System_Command
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
