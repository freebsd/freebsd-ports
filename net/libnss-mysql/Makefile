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

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE}
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_MYSQL=	yes

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500112
IGNORE=		NSS modules only supported on FreeBSD 5.1 or later
.endif

.include <bsd.port.post.mk>
