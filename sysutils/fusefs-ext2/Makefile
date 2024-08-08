PORTNAME=	fusefs-ext2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.11
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	FUSE module to mount ext2, ext3 and ext4 with read write support
WWW=		https://github.com/alperakcan/fuse-ext2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	mke2fs:sysutils/e2fsprogs-core
RUN_DEPENDS=	mke2fs:sysutils/e2fsprogs-core

USES=		autoreconf fuse libtool localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	alperakcan
GH_PROJECT=	fuse-ext2
GH_TAGNAME=	e8f1063

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/e2fsprogs
LDFLAGS+=	-L${LOCALBASE}/lib/e2fsprogs -Wl,--rpath \
		-Wl,${LOCALBASE}/lib/e2fsprogs

PLIST_FILES=	bin/fuse-ext2 \
		bin/fuse-ext2.probe \
		libdata/pkgconfig/fuse-ext2.pc \
		share/man/man1/fuse-ext2.1.gz

.include <bsd.port.mk>
