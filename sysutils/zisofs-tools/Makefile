PORTNAME=	zisofs-tools
PORTVERSION=	1.0.8
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	KERNEL_ORG/linux/utils/fs/zisofs

MAINTAINER=	chip-set@mail.ru
COMMENT=	User utilities for zisofs

PORTDOCS=	CHANGES COPYING INSTALL MRULES README

USES=		gmake tar:bzip2 desthack
GNU_CONFIGURE=	yes

MAKE_ARGS+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

PLIST_FILES=	bin/mkzftree \
		share/man/man1/mkzftree.1.gz

OPTIONS_DEFINE=	LFS DOCS
OPTIONS_DEFAULT=	LFS
LFS_DESC=	Enable Large Files Support

LFS_CONFIGURE_ENABLE=	largefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
