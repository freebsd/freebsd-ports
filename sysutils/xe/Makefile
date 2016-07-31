# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	xe
PORTVERSION=	0.6.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	t@tobik.me
COMMENT=	Simple xargs and apply replacement

LICENSE=	CC0-1.0

USE_GITHUB=	yes
GH_ACCOUNT=	chneukirchen

MAKE_ARGS=	CFLAGS="${CFLAGS}" \
		MANDIR="${PREFIX}/man"

PLIST_FILES=	bin/xe \
		man/man1/xe.1.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xe

.include <bsd.port.mk>
