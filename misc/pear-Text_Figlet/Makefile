# Ports collection makefile for:  pear-Text_Figlet
# Date created:			  15 December 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Text_Figlet
PORTVERSION=	0.8.1
CATEGORIES=	misc www pear

MAINTAINER=	antonio@php.net
COMMENT=	Render text using FIGlet fonts

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Text
FILES=		Figlet.php
DOCS=		README.TXT
EXAMPLES=	figlet.php 3-d.flf alligator2.flf bell.flf block.flf contessa.flf \
		cybermedium.flf isometric1.flf larry3d.flf script.flf slant.flf
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
