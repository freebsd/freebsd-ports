# Created by: Anish Mistry
# $FreeBSD$

PORTNAME=	fusefs
PORTVERSION=	2.9.3
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF/fuse/fuse-2.X/${PORTVERSION}
PKGNAMESUFFIX=	-libs
DISTNAME=	fuse-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FUSE allows filesystem implementation in userspace

OPTIONS_DEFINE=	DOCS

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MOUNT_FUSE_PATH=${PREFIX}/sbin
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install-strip
USES=		iconv libtool
USE_LDCONFIG=	yes

PORTDOCS=	*

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/fuse_kernel.h ${STAGEDIR}${PREFIX}/include/fuse
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/libs
	${INSTALL_DATA} ${WRKSRC}/doc/how-fuse-works ${WRKSRC}/doc/kernel.txt ${STAGEDIR}${DOCSDIR}/libs

.include <bsd.port.pre.mk>

.if ${OPSYS} == DragonFly
IGNORE=	fusefs has not been implemented on DragonFly
.endif

.include <bsd.port.post.mk>
