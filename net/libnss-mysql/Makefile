# Ports collection Makefile for:	libnss_mysql
# Date created:				05/05/2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	libnss-mysql
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libnss-mysql

MAINTAINER=	vd@FreeBSD.org
COMMENT=	NSS module using a MySQL database for backend

USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE}
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_MYSQL=	yes

.include <bsd.port.mk>
