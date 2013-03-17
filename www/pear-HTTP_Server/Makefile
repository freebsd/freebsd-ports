# Created by: Gerrit Beine (<tux@pinguru.net>)
# $FreeBSD$

PORTNAME=	HTTP_Server
PORTVERSION=	0.4.1
CATEGORIES=	www devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	HTTP server class

BUILD_DEPENDS=	${PEARDIR}/HTTP.php:${PORTSDIR}/www/pear-HTTP \
		${PEARDIR}/Net/Server.php:${PORTSDIR}/net/pear-Net_Server
RUN_DEPENDS=	${PEARDIR}/HTTP.php:${PORTSDIR}/www/pear-HTTP \
		${PEARDIR}/Net/Server.php:${PORTSDIR}/net/pear-Net_Server

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
