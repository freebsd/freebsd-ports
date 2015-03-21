# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	hanazono-fonts-ttf
PORTVERSION=	20131208
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	SFJP
MASTER_SITE_SUBDIR=	hanazono-font/60001
DISTNAME=	${PORTNAME:C/-.*//}-${PORTVERSION}

MAINTAINER=	lichray@gmail.com
COMMENT=	CJK Mincho-typeface developed by Hanazono University

LICENSE=	OFL11

USES=		fonts zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTNAME=	Hana
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC}/ && \
		${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
