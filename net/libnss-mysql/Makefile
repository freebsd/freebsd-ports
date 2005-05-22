# Ports collection Makefile for:	libnss_mysql
# Date created:				05/05/2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	libnss-mysql
PORTVERSION=	1.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libnss-mysql

MAINTAINER=	clement@FreeBSD.org
COMMENT=	NSS module using a MySQL database for backend

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql-lib=${LOCALBASE}/lib/mysql \
		--with-mysql-inc=${LOCALBASE}/include/mysql
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
USE_MYSQL=	yes

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500112
IGNORE=		NSS modules only supported on FreeBSD 5.1 or later
.endif

.include <bsd.port.post.mk>
