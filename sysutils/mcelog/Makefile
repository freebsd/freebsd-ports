# Created by: Jeremy Chadwick <freebsd@jdc.parodius.com>
# $FreeBSD$

PORTNAME=	mcelog
PORTVERSION=	167
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Collects and decodes Machine Check Exception data

LICENSE=	GPLv2

ONLY_FOR_ARCHS=		amd64 i386

TEST_DEPENDS=	bash:shells/bash

USES=		alias gmake shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	andikleen

SHEBANG_FILES=	tests/cache/inject tests/memdb/inject tests/page/inject \
		tests/pfa/inject tests/server/inject tests/socket/inject \
		tests/trigger tests/unknown/inject

MAKE_ENV+=	FREEBSD=1
MAKE_ARGS+=	CFLAGS="${CFLAGS}" prefix="${PREFIX}"
LDFLAGS+=	-lkvm

PLIST_FILES=	bin/mcelog man/man8/mcelog.8.gz

post-patch:
	@${ECHO} "${DISTVERSIONPREFIX}${PORTVERSION}" >${WRKSRC}/.os_version
	@${CP} ${FILESDIR}/memstream.c ${WRKSRC}/memstream.c
	@${REINPLACE_CMD} 's/\"unknown\"/\"${PORTVERSION}\"/' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mcelog ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mcelog.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
