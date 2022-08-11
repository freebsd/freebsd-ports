PORTNAME=	zisofs-tools
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	KERNEL_ORG/linux/utils/fs/zisofs

MAINTAINER=	chip-set@mail.ru
COMMENT=	User utilities for zisofs

PORTDOCS=	CHANGES COPYING INSTALL MRULES README

USES=		gmake tar:bzip2 desthack
GNU_CONFIGURE=	yes

MAKE_ARGS+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

PLIST_FILES=	bin/mkzftree \
		man/man1/mkzftree.1.gz

OPTIONS_DEFINE=	LFS DOCS
OPTIONS_DEFAULT=	LFS
LFS_DESC=	Enable Large Files Support

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MLFS}
CONFIGURE_ARGS+=	--disable-largefile
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
