# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD: head/security/linux-f10-libgcrypt/Makefile 362314 2014-07-20 12:06:46Z rene $

PORTNAME=	libgcrypt
PORTVERSION=	1.4.4
PORTREVISION=	2
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	General purpose crypto library based on code used in GnuPG

USE_LINUX=	f10
USE_LINUX_RPM=	yes

RPMVERSION=	1.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libgcrypt.so.11 lib/libgcrypt.so.11.5.2
PLIST_DIRS=	etc/gcrypt
DESCR=		${.CURDIR}/../libgcrypt/pkg-descr

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/gcrypt

.include <bsd.port.mk>
