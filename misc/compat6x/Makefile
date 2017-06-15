# Created by: mnag
# $FreeBSD$

PORTNAME=	compat6x
PORTVERSION=	6.4.604000.200810
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	LOCAL/mnag/compat6x \
		http://people.freebsd.org/~mnag/compat6x/
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convenience package to install the compat6x libraries

USES=	tar:bzip2
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64 sparc64
PLIST=		${PKGDIR}/pkg-plist.${ARCH}
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat
USE_LDCONFIG=	${TARGET_DIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
USE_LDCONFIG32=	${TARGET32_DIR}
.endif

do-install:
	@${MKDIR} -m 755 ${STAGEDIR}${TARGET_DIR}
	${RM} ${WRKSRC}/lib/libpthread.so.2
	(cd ${STAGEDIR}${TARGET_DIR} && ${LN} -sf libthr.so.2 libpthread.so.2)
	(cd ${WRKSRC}/lib && ${INSTALL_DATA} *.so.* ${STAGEDIR}${TARGET_DIR})
.if ${ARCH} == amd64
	@${MKDIR} ${STAGEDIR}${TARGET32_DIR}
	${RM} ${WRKSRC}/lib32/libpthread.so.2
	(cd ${STAGEDIR}${TARGET32_DIR} && ${LN} -sf libthr.so.2 libpthread.so.2)
	(cd ${WRKSRC}/lib32 && ${INSTALL_DATA} *.so.* ${STAGEDIR}${TARGET32_DIR})
.endif

.include <bsd.port.post.mk>
