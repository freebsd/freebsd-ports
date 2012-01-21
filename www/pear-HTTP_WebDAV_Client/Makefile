# Ports collection makefile for:  HTTP_WebDAV_Client
# Date created:			  14 Nov 2008
# Whom:				  Wen Heping<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HTTP_WebDAV_Client
PORTVERSION=	1.0.2
CATEGORIES=	www devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	WebDAV Stream Wrapper Class

BUILD_DEPENDS=	${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
RUN_DEPENDS:=	${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
