# Ports collection makefile for:  pear-Text_Figlet
# Date created:			  15 December 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Text_Figlet
PORTVERSION=	1.0.0
CATEGORIES=	misc www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Render text using FIGlet fonts

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Text
FILES=		Text/Figlet.php fonts/3-d.flf fonts/alligator2.flf fonts/bell.flf \
		fonts/block.flf fonts/contessa.flf fonts/cybermedium.flf fonts/isometric1.flf \
		fonts/larry3d.flf fonts/script.flf fonts/slant.flf
DOCS=		README.TXT
EXAMPLES=	hello_world.php listfonts.php
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
