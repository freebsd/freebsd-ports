# Ports collection makefile for:  pear-Services_Delicious
# Date created:			  2006/08/03
# Whom:				  chinsan <chisnan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Services_Delicious
PORTVERSION=	0.6.0
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR Client for the del.icio.us web service

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer \
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_DOS2UNIX=	yes
USE_PHP=	openssl

FILES=		Services/Delicious.php
EXAMPLES=	addPost.php config.php deletePost.php getDates.php getPosts.php \
		getTags.php renameTag.php
DOCS=		api.txt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
