# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	patchelf
PORTVERSION=	0.9
CATEGORIES=	sysutils

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Utility to modify the dynamic linker

LICENSE=       GPLv3+
LICENSE_FILE=  ${WRKSRC}/COPYING

USES=          autoreconf gmake
GNU_CONFIGURE= yes

USE_GITHUB=    yes
GH_ACCOUNT=    NixOS
GH_PROJECT=    patchelf

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
