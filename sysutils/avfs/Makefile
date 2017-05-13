# Created by: Evgeny Zhirnov <jirnov@gmail.com>
# $FreeBSD$

PORTNAME=	avfs
PORTVERSION=	1.0.5
CATEGORIES=	sysutils
MASTER_SITES=	SF/avf/${PORTNAME}/${PORTVERSION}

MAINTAINER=	mp39590@gmail.com
COMMENT=	Virtual File System library

# FUSE daemon is licensed as GPLv2, shared library is LGPLv2
LICENSE=	LGPL20 GPLv2
LICENSE_COMB=	multi

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

USES=		libtool pkgconfig tar:bz2 shebangfix perl5
USE_PERL5=	run
SHEBANG_FILES=	extfs/uimg scripts/umountavfs scripts/mountavfs
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL="${PERL}"

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DEBUG FUSE
OPTIONS_SUB=	yes
DEBUG_CONFIGURE_ENABLE=	debug
FUSE_CONFIGURE_ENABLE=	fuse
FUSE_USES=	fuse

.include <bsd.port.mk>
