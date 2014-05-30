# Created by: Nosov Artem <chip-set@mail.ru>
# $FreeBSD$

PORTNAME=	zisofs-tools
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_KERNEL_ORG}
MASTER_SITE_SUBDIR=	linux/utils/fs/zisofs

MAINTAINER=	chip-set@mail.ru
COMMENT=	User utilities for zisofs

PORTDOCS=	CHANGES COPYING INSTALL MRULES README

USE_AUTOTOOLS=	autoconf
USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes

MAKE_ARGS+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

MAN1=		mkzftree.1

PLIST_FILES=	bin/mkzftree

OPTIONS_DEFINE=	LFS DOCS
OPTIONS_DEFAULT=	LFS
LFS_DESC=	Enable Large Files Support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MLFS}
CONFIGURE_ARGS+=	--disable-largefile
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
