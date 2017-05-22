# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	Net_CDDB
PORTVERSION=	0.3.0
CATEGORIES=	net audio www pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PEAR class that access and query CDDB audio-CD servers

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:net/pear-Net_Socket \
		${PEARDIR}/HTTP/Request.php:www/pear-HTTP_Request \
		${PEARDIR}/MDB2.php:databases/pear-MDB2
RUN_DEPENDS=	${PEARDIR}/Net/Socket.php:net/pear-Net_Socket \
		${PEARDIR}/HTTP/Request.php:www/pear-HTTP_Request \
		${PEARDIR}/MDB2.php:databases/pear-MDB2

USES=		dos2unix pear

.include <bsd.port.mk>
