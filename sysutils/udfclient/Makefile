# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	udfclient
PORTVERSION=	0.8.8
CATEGORIES=	sysutils
MASTER_SITES=	OPENBSD/distfiles \
		LOCAL/miwi
DISTFILES=	UDFclient.${PORTVERSION}.tgz

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Tools for UDF filesystem

BROKEN=		unfetchable

LICENSE=	ClArtistic

WRKSRC=		${WRKDIR}/UDFclient.${PORTVERSION}

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	FUSE DEBUG
FUSE_DESC=	udfclientfs via FUSE

PLIST_FILES=	bin/udfdump \
		bin/udfclient \
		bin/newfs_udf \
		bin/cd_sessions \
		bin/cd_disect \
		bin/mmc_format

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFUSE}
UDFCLIENTFS_NAME=	udfclientfs
UDFCLIENTFS_VERSION=	0.6
UDFCLIENTFS_DIR=	${WRKDIR}/udfclientfs

MASTER_SITES+=	http://www.icyb.net.ua/~avg/distfiles/:fuse \
		LOCAL/avg:fuse
DISTFILES+=	${UDFCLIENTFS_NAME}-${UDFCLIENTFS_VERSION}.tgz:fuse
EXTRA_PATCHES+=	${UDFCLIENTFS_DIR}/${UDFCLIENTFS_NAME}.patch
PATCH_ARGS+=	--ignore-whitespace

USES+=		fuse

PLIST_FILES+=	bin/${UDFCLIENTFS_NAME}
.endif

.if ${PORT_OPTIONS:MDEBUG}
CFLAGS+=	-O0 -ggdb3
.endif

post-patch:
.if ${PORT_OPTIONS:MFUSE}
	${CP} ${UDFCLIENTFS_DIR}/${UDFCLIENTFS_NAME}.c ${WRKSRC}
.endif

.include <bsd.port.mk>
