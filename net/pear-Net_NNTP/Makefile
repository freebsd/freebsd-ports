# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	Net_NNTP
PORTVERSION=	1.5.0
PORTEPOCH=	1
CATEGORIES=	net news pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR implementation of the NNTP protocol

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
