# Created by: Anish Mistry
# $FreeBSD$

PORTNAME=	fusefs
PORTVERSION=	2.9.3
CATEGORIES=	sysutils
MASTER_SITES=	SF/fuse/fuse-2.X/${PORTVERSION}
PKGNAMESUFFIX=	-libs
DISTNAME=	fuse-${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	FUSE allows filesystem implementation in userspace

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MOUNT_FUSE_PATH=${PREFIX}/sbin
USE_LDCONFIG=	yes
USES=		iconv
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
TXT_DOCS=	how-fuse-works \
		kernel.txt

MAN1=	fusermount.1 \
	ulockmgr_server.1
MAN8=	mount.fuse.8


.include <bsd.port.options.mk>

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/fuse_kernel.h ${PREFIX}/include/fuse
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/libs
.for i in ${TXT_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/$i ${DOCSDIR}/libs
.endfor
.endif


.include <bsd.port.mk>
