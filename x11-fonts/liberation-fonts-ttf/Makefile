# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	liberation-fonts-ttf
PORTVERSION=	2.00.1
PORTEPOCH=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://fedorahosted.org/releases/l/i/liberation-fonts/	\
		LOCAL/thierry

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Liberation fonts from Red Hat to replace MS TTF fonts

LICENSE=	OFL11

USES=		fonts
USE_XORG=	x11

SUB_FILES=	pkg-message

FONTNAME=	Liberation
INSTDAT=	AUTHORS
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${INSTDAT} *.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
