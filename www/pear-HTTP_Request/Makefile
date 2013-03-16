# Created by: Thierry Thomas (<thierry@FreeBSD.org>)
# $FreeBSD$

PORTNAME=	HTTP_Request
PORTVERSION=	1.4.4
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR classes providing an easy way to perform HTTP requests

BUILD_DEPENDS=	${PEARDIR}/Net/URL.php:${PORTSDIR}/net/pear-Net_URL		\
		${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${PEARDIR}/Net/URL.php:${PORTSDIR}/net/pear-Net_URL		\
		${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
