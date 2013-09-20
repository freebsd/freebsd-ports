# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	libgcrypt
PORTVERSION=	1.4.4
CATEGORIES=	security linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	General purpose crypto library based on code used in GnuPG

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	1.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libgcrypt.so.11 lib/libgcrypt.so.11.5.2
PLIST_DIRSTRY=	etc/gcrypt
DESCR=		${.CURDIR}/../libgcrypt/pkg-descr

NO_STAGE=	yes
post-install:
	@${MKDIR} ${PREFIX}/etc/gcrypt

.include <bsd.port.mk>
