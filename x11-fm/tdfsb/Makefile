# New ports collection makefile for:	TDFSB
# Date created:				31 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tdfsb
PORTVERSION=	0.0.10
PORTREVISION=	2
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.determinate.net/webdata/data/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D filesystem browser

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	smpeg.1:${PORTSDIR}/multimedia/smpeg

USE_GL=		glut
USE_SDL=	image sdl
USE_PKGCONFIG=	yes

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

CPPFLAGS+=	`${LOCALBASE}/bin/pkgconf --cflags SDL_image glut` \
		`${LOCALBASE}/bin/smpeg-config --cflags`
LDFLAGS+=	`${LOCALBASE}/bin/pkgconf --libs SDL_image glut` \
		`${LOCALBASE}/bin/smpeg-config --libs`

.include <bsd.port.pre.mk>

do-build:
	(cd ${BUILD_WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} ${PORTNAME}.c \
		-o ${PORTNAME} ${LDFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
