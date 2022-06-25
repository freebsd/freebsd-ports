PORTNAME=	bindfs
DISTVERSION=	1.16.1
CATEGORIES=	sysutils
MASTER_SITES=	https://bindfs.org/downloads/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	doralitze@chaotikum.org
COMMENT=	FUSE based bindfs implementation way more powerful than nullfs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fuse:3 localbase:ldflags pkgconfig
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/bindfs \
		man/man1/bindfs.1.gz

.include <bsd.port.pre.mk>

.if ${LIBFUSE_VER} == 3
FUSEPKG=	fuse3
CONFIGURE_ENV+=	FUSE_CFLAGS="-I${LOCALBASE}/include/fuse3" \
		FUSE_LIBS="-L${LOCALBASE}/lib -lfuse3"
LDFLAGS+=	-lthr
.endif

FUSE_VERSION=	"`pkgconf --modversion ${FUSEPKG} | \
		${SED} -E 's,^([0-9]+)\.([0-9]+)\..*,\1\2,'`"

.include <bsd.port.post.mk>
