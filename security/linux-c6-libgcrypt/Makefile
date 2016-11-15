# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	libgcrypt
PORTVERSION=	1.4.5
PORTREVISION=	4
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	General purpose crypto library based on code used in GnuPG (Linux CentOS ${LINUX_DIST_VER})

RPMVERSION=	12.el6_8
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

PORTDOCS=	AUTHORS COPYING.LIB NEWS THANKS
DESCR=		${.CURDIR}/../libgcrypt/pkg-descr

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/gcrypt

.include <bsd.port.mk>
