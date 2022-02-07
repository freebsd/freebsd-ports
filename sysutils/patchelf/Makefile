# Created by: William Grzybowski <wg@FreeBSD.org>

PORTNAME=	patchelf
DISTVERSION=	0.14.3
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/NixOS/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utility to modify the dynamic linker

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lang gmake tar:bz2

GNU_CONFIGURE=	yes
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
