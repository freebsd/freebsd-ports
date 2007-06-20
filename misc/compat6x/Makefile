# New ports collection makefile for:	compat6x
# Date created:				30 Nov 2006
# Whom:					mnag
#
# $FreeBSD$
#

PORTNAME=	compat6x
PORTVERSION=	6.2.602110.200706
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	mnag/compat6x
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A convenience package to install the compat6x libraries

USE_BZIP2=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64 alpha sparc64
PLIST=		${PKGDIR}/pkg-plist.${ARCH}
USE_LDCONFIG=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/compat
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat
USE_LDCONFIG=	${TARGET_DIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700043
IGNORE=		is for FreeBSD 7.x and newer
.endif

.if ${ARCH} == amd64
PLIST_SUB+=	LDCONFIG_LIB32="${LDCONFIG} -32"
USE_LDCONFIG32=	${TARGET32_DIR}
.endif

do-install:
	@${MKDIR} ${TARGET_DIR}
	(cd ${WRKSRC}/lib && ${INSTALL_DATA} *.so.* ${TARGET_DIR})
.if ${ARCH} == amd64
	@${MKDIR} ${TARGET32_DIR}
	(cd ${WRKSRC}/lib32 && ${INSTALL_DATA} *.so.* ${TARGET32_DIR})
.endif

# Include this file to use install-ldconfig-file
.include "${PORTSDIR}/misc/ldconfig_compat/bsd.ldconfig.mk"

post-install:	install-ldconfig-file
.if ${ARCH} == amd64
	@${LDCONFIG} -32 -m ${TARGET32_DIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
