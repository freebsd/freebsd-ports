# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	patchelf
PORTVERSION=	0.11
CATEGORIES=	sysutils

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Utility to modify the dynamic linker

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	NixOS

GNU_CONFIGURE=	yes
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
