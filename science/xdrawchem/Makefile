# $FreeBSD$

PORTNAME=	xdrawchem
DISTVERSION=	1.10.2-1
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Two-dimensional molecule drawing program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/GPL.txt

LIB_DEPENDS=	libopenbabel.so:science/openbabel

USES=		compiler:c++11-lang gl qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	bryanherger
USE_QT=		core gui network printsupport widgets xml buildtools_build
USE_GL=		gl

WRKSRC_SUBDIR=	${PORTNAME}-qt5

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
