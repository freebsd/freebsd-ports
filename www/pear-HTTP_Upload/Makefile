# Ports collection makefile for:  pear-HTTP_Upload
# Date created:			  13 December 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTTP_Upload
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	www devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy and secure managment of files submitted via HTML Forms

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTTP
FILES=		Upload.php
EXAMPLES=	upload_example.php
_EXAMPLESDIR=	docs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
