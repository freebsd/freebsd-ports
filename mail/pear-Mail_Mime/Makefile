# Ports collection makefile for:  pear-Mail_Mime
# Date created:			  24 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Mail_Mime
PORTVERSION=	1.4.0a3
CATEGORIES=	mail www pear

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	PEAR classes to create and decode MIME messages

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Mail
FILES=		mime.php mimeDecode.php mimePart.php
DATA=		xmail.dtd xmail.xsl
_DATADIR=	.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
