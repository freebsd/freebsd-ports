# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	patchelf
DISTVERSION=	0.12
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/NixOS/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Utility to modify the dynamic linker

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lang gmake tar:bz2
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}.20200827.8d3a16e

GNU_CONFIGURE=	yes
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
