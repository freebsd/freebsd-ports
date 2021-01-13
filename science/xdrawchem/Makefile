# $FreeBSD$

PORTNAME=	xdrawchem
DISTVERSION=	1.11.0-2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Two-dimensional molecule drawing program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libopenbabel.so:science/openbabel

USES=		compiler:c++11-lang gl qmake qt:5
USE_QT=		core gui network printsupport svg widgets xml buildtools_build
USE_GL=		gl

USE_GITLAB=	yes
GL_SITE=	https://salsa.debian.org
GL_ACCOUNT=	georgesk
GL_COMMIT=	a3f74c34eb09fa72ee16848ec6901049ca5309d5

pre-configure:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|'	\
		${WRKSRC}/xdrawchem.pro

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
