# New ports collection makefile for:    fusefs-libs
# Date created:         01 October 2005
# Whom:                 Anish Mistry
# $FreeBSD$
#

PORTNAME=	fusefs
PORTVERSION=	2.7.4
CATEGORIES=	sysutils
MASTER_SITES=	SF/fuse/fuse-2.X/${PORTVERSION}
PKGNAMESUFFIX=	-libs
DISTNAME=	fuse-${PORTVERSION}

MAINTAINER=	amistry@am-productions.biz
COMMENT=	FUSE allows filesystem implementation in userspace

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MOUNT_FUSE_PATH=${PREFIX}/sbin \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
USE_ICONV=	yes
CONFIGURE_ARGS=	--disable-kernel-module --prefix=${PREFIX} \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
TXT_DOCS=	how-fuse-works \
		kernel.txt

post-patch:
	${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS},' \
		-e 's,-D_FILE_OFFSET_BITS=64,-D_FILE_OFFSET_BITS=64 ${PTHREAD_CFLAGS},' \
		${WRKSRC}/fuse.pc.in
	${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS},' \
		${WRKSRC}/lib/Makefile.in \
		${WRKSRC}/example/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/fuse_kernel.h ${PREFIX}/include/fuse

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/libs
.for i in ${TXT_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/$i ${DOCSDIR}/libs
.endfor
.endif

.include <bsd.port.mk>
