# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	unicode-uhoai
PORTVERSION=	2.1
PORTREVISION=	5
CATEGORIES=	vietnamese x11-fonts
MASTER_SITES=	LOCAL/obrien
DISTNAME=	uhoaiw21

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unicode TrueType Font with UHoai Vietnamese encoding

USES=		fonts zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	%%FONTSDIR%%/uhoaiw21.ttf

FONTNAME=	TrueType

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/UHOAIW21.TTF ${STAGEDIR}${FONTSDIR}/uhoaiw21.ttf

.include <bsd.port.mk>
