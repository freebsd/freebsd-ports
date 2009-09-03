# New ports collection makefile for:	compat7x
# Date created:				18 Aug 2009
# Whom:					garga
#
# $FreeBSD$
#

PORTNAME=	compat7x
PORTVERSION=	7.2.702000.200906.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	garga/compat
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A convenience package to install the compat7x libraries

USE_BZIP2=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64 sparc64
PLIST=		${PKGDIR}/pkg-plist.${ARCH}
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat
USE_LDCONFIG=	${TARGET_DIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800105
IGNORE=		is for FreeBSD 8.x and newer
.endif

.if ${ARCH} == amd64
PLIST_SUB+=	LDCONFIG_LIB32="${LDCONFIG} -32"
USE_LDCONFIG32=	${TARGET32_DIR}
.endif

do-install:
	@${MKDIR} ${TARGET_DIR}
	(cd ${WRKSRC}/lib && ${INSTALL_DATA} *.so.* ${TARGET_DIR})
	(cd ${TARGET_DIR} && ${LN} -sf /lib/libthr.so.3 libkse.so.3)
.if ${ARCH} == amd64
	@${MKDIR} ${TARGET32_DIR}
	(cd ${TARGET32_DIR} && ${LN} -sf /usr/lib32/libthr.so.3 libkse.so.3)
	(cd ${WRKSRC}/lib32 && ${INSTALL_DATA} *.so.* ${TARGET32_DIR})
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
