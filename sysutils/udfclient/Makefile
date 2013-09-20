# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	udfclient
PORTVERSION=	0.7.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.13thmonkey.org/udfclient/releases/ \
		${MASTER_SITE_NETBSD} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi
DISTFILES=	UDFclient.${PORTVERSION}.tgz

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Tools for UDF filesystem

WRKSRC=		${WRKDIR}/UDFclient.${PORTVERSION}

GNU_CONFIGURE=	yes
MAKE_ARGS+=	INSTALL="${INSTALL_PROGRAM}"

OPTIONS_DEFINE=	FUSE DEBUG
FUSE_DESC=	udfclientfs via FUSE

PLIST_FILES=	bin/udfdump \
		bin/udfclient \
		bin/newfs_udf \
		bin/cd_sessions \
		bin/cd_disect \
		bin/mmc_format

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFUSE}
UDFCLIENTFS_NAME=	udfclientfs
UDFCLIENTFS_VERSION=	0.4
UDFCLIENTFS_DIR=	${WRKDIR}/udfclientfs

MASTER_SITES+=	http://www.icyb.net.ua/~avg/distfiles/:fuse
DISTFILES+=	${UDFCLIENTFS_NAME}-${UDFCLIENTFS_VERSION}.tgz:fuse
EXTRA_PATCHES+=	${UDFCLIENTFS_DIR}/${UDFCLIENTFS_NAME}.patch

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
