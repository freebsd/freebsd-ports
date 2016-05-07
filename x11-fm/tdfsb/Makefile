# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	tdfsb
PORTVERSION=	0.0.10
PORTREVISION=	7
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.determinate.net/webdata/data/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D filesystem browser

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsmpeg.so:multimedia/smpeg

USE_GL=		glut
USE_SDL=	image sdl
USES=		pkgconfig

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

CPPFLAGS+=	`${LOCALBASE}/bin/pkgconf --cflags SDL_image gl` \
		`${LOCALBASE}/bin/smpeg-config --cflags` \
		-I ${LOCALBASE}/include
LDFLAGS+=	`${LOCALBASE}/bin/pkgconf --libs SDL_image gl` \
		`${LOCALBASE}/bin/smpeg-config --libs` \
		-L ${LOCALBASE}/lib -lGLU -lglut -lm

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${BUILD_WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} ${PORTNAME}.c \
		-o ${PORTNAME} ${LDFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
