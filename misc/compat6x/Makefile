# New ports collection makefile for:	compat6x
# Date created:				30 Nov 2006
# Whom:					mnag
#
# $FreeBSD$
#

PORTNAME=	compat6x
PORTVERSION=	6.4.604000.200810
PORTREVISION=	3
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
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat
USE_LDCONFIG=	${TARGET_DIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700043
IGNORE=		is for FreeBSD 7.x and newer
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: fails to link lib/compat/libpthread.so.2
.endif

.if ${ARCH} == amd64
PLIST_SUB+=	LDCONFIG_LIB32="${LDCONFIG} -32"
USE_LDCONFIG32=	${TARGET32_DIR}
.endif

do-install:
	@${MKDIR} ${TARGET_DIR}
.if ${OSVERSION} >= 800105
	${RM} -f ${WRKSRC}/lib/libpthread.so.2
	(cd ${TARGET_DIR} && ${LN} -sf libthr.so.2 libpthread.so.2)
.endif
	(cd ${WRKSRC}/lib && ${INSTALL_DATA} *.so.* ${TARGET_DIR})
.if ${ARCH} == amd64
	@${MKDIR} ${TARGET32_DIR}
. if ${OSVERSION} >= 800105
	${RM} -f ${WRKSRC}/lib32/libpthread.so.2
	(cd ${TARGET32_DIR} && ${LN} -sf libthr.so.2 libpthread.so.2)
. endif
	(cd ${WRKSRC}/lib32 && ${INSTALL_DATA} *.so.* ${TARGET32_DIR})
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
