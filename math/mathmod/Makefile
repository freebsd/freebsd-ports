# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	MathMod
PORTVERSION=	11.0
CATEGORIES=	math graphics

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Mathematical modeling software

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	parisolab
GH_PROJECT=	${PORTNAME:tl}

USES=		compiler:c++11-lang dos2unix gl qmake qt:5
USE_GL=		gl
USE_QT=		buildtools_build core gui opengl qmake_build widgets

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
