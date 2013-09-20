# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	libnss-mysql
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	vd@FreeBSD.org
COMMENT=	NSS module using a MySQL database for backend

USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE}
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_MYSQL=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
