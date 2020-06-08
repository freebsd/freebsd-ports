# Created by: Hondareyte <lhondareyte@laposte.net>
# $FreeBSD$

PORTNAME=	minipro
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	lhondareyte@laposte.net
COMMENT=	CLI for MiniPRO TL866xx chip programmers

LICENSE=	GPLv3

BUILD_DEPENDS=	gsed:textproc/gsed
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c11 gmake pkgconfig shebangfix
USE_GITLAB=	yes

GL_ACCOUNT=	DavidGriffith
GL_COMMIT=	e6fb06822e6685886a045ae98c3c82d832bd8e9c
GL_PROJECT=	${PORTNAME}
BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed
SHEBANG_FILES=	miniprohex
PLIST_FILES=	bin/minipro \
		bin/miniprohex \
		man/man1/minipro.1.gz

post-install:
	@${GZIP_CMD} ${STAGEDIR}${PREFIX}/man/man1/minipro.1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
