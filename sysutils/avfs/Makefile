# Created by: Evgeny Zhirnov <jirnov@gmail.com>
# $FreeBSD$

PORTNAME=	avfs
PORTVERSION=	1.0.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/avf/${PORTNAME}/${PORTVERSION}

MAINTAINER=	mp39590@gmail.com
COMMENT=	Virtual File System library

# FUSE daemon is licensed as GPLv2, shared library is LGPLv2
LICENSE=	LGPL20 GPLv2
LICENSE_COMB=	multi

USES=		libtool pkgconfig tar:bz2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DEBUG FUSE
OPTIONS_SUB=	yes
DEBUG_CONFIGURE_ENABLE=	debug
FUSE_CONFIGURE_ENABLE=	fuse
FUSE_USES=	fuse shebangfix
FUSE_RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFUSE}
SHEBANG_FILES=	scripts/umountavfs scripts/mountavfs
.endif

.include <bsd.port.mk>
