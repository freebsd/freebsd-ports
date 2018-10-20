# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	liberation-fonts-ttf
PORTVERSION=	2.00.3
PORTEPOCH=	2
CATEGORIES=	x11-fonts

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Liberation fonts from Red Hat to replace MS TTF fonts

LICENSE=	OFL11

BUILD_DEPENDS=	fontforge:print/fontforge	\
		fonttools-3.6:print/py-fonttools@py36

USE_GITHUB=	yes
GH_ACCOUNT=	liberationfonts
GH_PROJECT=	liberation-fonts

USES=		fonts gmake python:3.3+,build
USE_XORG=	x11

NO_ARCH=	yes
SUB_FILES=	pkg-message

SCRIPT_F=	scripts/setisFixedPitch-fonttools.py

FONTNAME=	Liberation

pre-configure:
	${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|' ${WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's|/usr/bin/python3| ${PYTHON_CMD}|'	\
		${WRKSRC}/${SCRIPT_F}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC}/${PORTNAME}-${PORTVERSION} && \
		${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
