PORTNAME=	xdrawchem
DISTVERSION=	1.11.1-2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Two-dimensional molecule drawing program
WWW=		https://sourceforge.net/projects/xdrawchem/ \
		https://github.com/bryanherger/xdrawchem

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libopenbabel.so:science/openbabel

USES=		compiler:c++11-lang gl pkgconfig qmake qt:5
USE_QT=		core gui network printsupport svg widgets xml buildtools:build
USE_GL=		gl

USE_GITLAB=	yes
GL_SITE=	https://salsa.debian.org
GL_ACCOUNT=	georgesk
GL_TAGNAME=	48f2e4817be451550a2cd80263344642a8611b15

pre-configure:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|'	\
		${WRKSRC}/xdrawchem.pro

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
