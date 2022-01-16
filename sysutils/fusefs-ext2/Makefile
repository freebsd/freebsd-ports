# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	fusefs-ext2
PORTVERSION=	0.0.10
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	FUSE module to mount ext2, ext3 and ext4 with read write support

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	mke2fs:sysutils/e2fsprogs
RUN_DEPENDS=	mke2fs:sysutils/e2fsprogs

USES=		autoreconf libtool fuse pkgconfig localbase:ldflags
USE_GITHUB=	yes

GH_PROJECT=	fuse-ext2
GH_ACCOUNT=	alperakcan
GH_TAGNAME=	ea7bacf

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/e2fsprogs
LDFLAGS+=	-L${LOCALBASE}/lib/e2fsprogs -Wl,--rpath -Wl,${LOCALBASE}/lib/e2fsprogs

PLIST_FILES=	bin/fuse-ext2 bin/fuse-ext2.probe \
		man/man1/fuse-ext2.1.gz \
		libdata/pkgconfig/fuse-ext2.pc

.include <bsd.port.mk>
