# $FreeBSD$

PORTNAME=	gnu-unifont-ttf
PORTVERSION=	7.0.03
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	GNU/unifont/unifont-${PORTVERSION}
DISTNAME=	unifont-${PORTVERSION}

MAINTAINER=	bsdports@gmail.com
COMMENT=	Unicode TrueType Font

USES=		fonts

NO_BUILD=	yes
WRKSRC_SUBDIR=	font/precompiled

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/unifont-${PORTVERSION}.ttf \
		${STAGEDIR}${FONTSDIR}/unifont.ttf
	${INSTALL_DATA} ${WRKSRC}/unifont_csur-${PORTVERSION}.ttf \
		${STAGEDIR}${FONTSDIR}/unifont_csur.ttf
	${INSTALL_DATA} ${WRKSRC}/unifont_upper-${PORTVERSION}.ttf \
		${STAGEDIR}${FONTSDIR}/unifont_upper.ttf
	${INSTALL_DATA} ${WRKSRC}/unifont_upper_csur-${PORTVERSION}.ttf \
		${STAGEDIR}${FONTSDIR}/unifont_upper_csur.ttf

.include <bsd.port.mk>
