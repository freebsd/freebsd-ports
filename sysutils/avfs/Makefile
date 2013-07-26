# Created by: Evgeny Zhirnov <jirnov@gmail.com>
# $FreeBSD$

PORTNAME=	avfs
PORTVERSION=	0.9.9
CATEGORIES=	sysutils
MASTER_SITES=	SF/avf/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jirnov@gmail.com
COMMENT=	A Virtual File System

BUILD_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-08-27
BROKEN=		does not package

NO_INSTALL_MANPAGES=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -liconv

GNU_CONFIGURE=	yes
USES=		fuse
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG LIBRARY FUSE
OPTIONS_DEFAULT=	FUSE
LIBRARY_DESC=	Enable library
FUSE_DESC=	Enable fuse

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if ${PORT_OPTIONS:MLIBRARY}
CONFIGURE_ARGS+=	--enable-library
PLIST_SUB+=	LIBRARY=""
.else
CONFIGURE_ARGS+=	--disable-library
PLIST_SUB+=	LIBRARY="@comment "
.endif

.if ${PORT_OPTIONS:MFUSE}
CONFIGURE_ARGS+=	--enable-fuse
PLIST_SUB+=	FUSE=""
.else
CONFIGURE_ARGS+=	--disable-fuse
PLIST_SUB+=	FUSE="@comment "
.endif

.include <bsd.port.mk>
