# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	umr
PORTVERSION=	0.3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.oldunreal.com/mods/other/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unreal Media Ripper


PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
