# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	Services_SharedBook
PORTVERSION=	0.2.6
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP wrapper for SharedBook Open API

BUILD_DEPENDS=	${PEARDIR}/HTTP/Client.php:${PORTSDIR}/www/pear-HTTP_Client
RUN_DEPENDS=	${PEARDIR}/HTTP/Client.php:${PORTSDIR}/www/pear-HTTP_Client

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
