# New ports collection makefile for:	avfs
# Date created:				2008-06-14
# Whom:					Evgeny Zhirnov <jirnov@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	avfs
PORTVERSION=	0.9.8
CATEGORIES=	sysutils
MASTER_SITES=	SF/avf/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jirnov@gmail.com
COMMENT=	A Virtual File System

BUILD_DEPENDS=	${LOCALBASE}/include/fuse.h:${PORTSDIR}/sysutils/fusefs-libs \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

NO_INSTALL_MANPAGES=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib -liconv"

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

OPTIONS=	DEBUG "Enable debug" off \
		LIBRARY "Enable library" off \
		FUSE "Enable fuse" on

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if defined(WITH_LIBRARY)
CONFIGURE_ARGS+=	--enable-library
PLIST_SUB+=	LIBRARY=""
.else
CONFIGURE_ARGS+=	--disable-library
PLIST_SUB+=	LIBRARY="@comment "
.endif

.if defined(WITH_FUSE)
CONFIGURE_ARGS+=	--enable-fuse
PLIST_SUB+=	FUSE=""
.else
CONFIGURE_ARGS+=	--disable-fuse
PLIST_SUB+=	FUSE="@comment "
.endif

.include <bsd.port.post.mk>
