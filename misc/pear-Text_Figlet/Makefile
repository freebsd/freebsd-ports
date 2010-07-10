# Ports collection makefile for:  pear-Text_Figlet
# Date created:			  15 December 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Text_Figlet
PORTVERSION=	1.0.2
CATEGORIES=	misc www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Render text using FIGlet fonts

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Text
FILES=		Text/Figlet.php fonts/makisupa.flf
DOCS=		README.TXT
EXAMPLES=	hello_world.php
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
