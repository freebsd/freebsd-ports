# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	libgcrypt
PORTVERSION=	1.4.5
PORTREVISION=	3
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	General purpose crypto library based on code used in GnuPG (Linux CentOS ${LINUX_DIST_VER})

USE_LINUX=	c6
USE_LINUX_RPM=	yes
RPMVERSION=	11.el6_4
USE_LDCONFIG=	yes

DOCSDIR=	usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING.LIB NEWS THANKS
DESCR=		${.CURDIR}/../libgcrypt/pkg-descr

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/gcrypt

.include <bsd.port.mk>
