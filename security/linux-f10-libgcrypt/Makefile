# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD: head/security/linux-f10-libgcrypt/Makefile 362314 2014-07-20 12:06:46Z rene $

PORTNAME=	libgcrypt
PORTVERSION=	1.4.4
CATEGORIES=	security linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	General purpose crypto library based on code used in GnuPG

#FORBIDDEN=	http://www.freshports.org/vuxml.php?vid=689c2bf7-0701-11e3-9a25-002590860428

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	1.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libgcrypt.so.11 lib/libgcrypt.so.11.5.2
PLIST_DIRSTRY=	etc/gcrypt
DESCR=		${.CURDIR}/../libgcrypt/pkg-descr

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/gcrypt

.include <bsd.port.mk>
