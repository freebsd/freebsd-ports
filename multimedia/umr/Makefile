# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	umr
PORTVERSION=	0.3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.oldunreal.com/mods/other/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unreal Media Ripper

BROKEN=		unfetchable
DEPRECATED=	Unfetchable, unmaintained
EXPIRATION_DATE=	2019-10-16

PLIST_FILES=	bin/${PORTNAME}
FETCH_AFTER_ARGS=	--referer=http://www.oldunreal.com/mods.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
