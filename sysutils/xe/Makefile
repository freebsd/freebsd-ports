# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	xe
PORTVERSION=	0.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Simple xargs and apply replacement

LICENSE=	CC0-1.0

TEST_DEPENDS=	prove:lang/perl5.24

USE_GITHUB=	yes
GH_ACCOUNT=	chneukirchen

MAKE_ARGS=	CFLAGS="${CFLAGS}" \
		MANDIR="${PREFIX}/man"
TEST_TARGET=	check

PLIST_FILES=	bin/xe \
		man/man1/xe.1.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xe

.include <bsd.port.mk>
