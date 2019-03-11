# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	hanazono-fonts-ttf
PORTVERSION=	20170904
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	OSDN/hanazono-font/68253
DISTNAME=	${PORTNAME:C/-.*//}-${PORTVERSION}

MAINTAINER=	lichray@gmail.com
COMMENT=	CJK Mincho-typeface developed by Hanazono University

LICENSE=	OFL11

USES=		fonts zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTNAME=	Hana
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
