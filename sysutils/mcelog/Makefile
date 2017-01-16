# Created by: Jeremy Chadwick <freebsd@jdc.parodius.com>
# $FreeBSD$

PORTNAME=	mcelog
PORTVERSION=	147
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Collects and decodes Machine Check Exception data

LICENSE=	GPLv2

TEST_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	andikleen

ONLY_FOR_ARCHS=	amd64 i386 ia64

USES=		alias gmake shebangfix

SHEBANG_FILES=	tests/cache/inject tests/memdb/inject tests/page/inject \
		tests/pfa/inject tests/server/inject tests/socket/inject \
		tests/trigger tests/unknown/inject

MAKE_ENV+=	FREEBSD=1
LDFLAGS+=	-lkvm

PLIST_FILES=	bin/mcelog man/man8/mcelog.8.gz

post-patch:
	@${CP} ${FILESDIR}/memstream.c ${WRKSRC}/memstream.c
	@${REINPLACE_CMD} 's/\"unknown\"/\"${PORTVERSION}\"/' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mcelog ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mcelog.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
