# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	unicode-uhoai
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	vietnamese x11-fonts
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien
DISTNAME=	uhoaiw21

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Unicode TrueType Font with UHoai Vietnamese encoding

USES=		zip:infozip
NO_WRKSUBDIR=	yes
NO_BUILD=	taken care of in do-install target

BUILD_DEPENDS=	ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir \
		bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

EXTRACT_BEFORE_ARGS=	-qoL

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/fonts/TrueType
	${INSTALL_DATA} ${WRKSRC}/uhoaiw21.ttf \
		${STAGEDIR}${PREFIX}/lib/X11/fonts/TrueType

.include <bsd.port.mk>
