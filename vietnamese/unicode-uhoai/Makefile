# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	unicode-uhoai
PORTVERSION=	2.1
PORTREVISION=	4
CATEGORIES=	vietnamese x11-fonts
MASTER_SITES=	LOCAL/obrien
DISTNAME=	uhoaiw21

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unicode TrueType Font with UHoai Vietnamese encoding

USES=		fonts zip:infozip
NO_WRKSUBDIR=	yes
NO_BUILD=	taken care of in do-install target

FONTNAME=	TrueType
EXTRACT_BEFORE_ARGS=	-qoL

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/uhoaiw21.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
