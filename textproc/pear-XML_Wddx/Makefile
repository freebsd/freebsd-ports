# Ports collection makefile for:  pear-XML_Wddx
# Date created:			  30 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	XML_Wddx
PORTVERSION=	1.0.2
CATEGORIES=	textproc devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Wddx pretty serializer and deserializer

BUILD_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		XML/Wddx.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
