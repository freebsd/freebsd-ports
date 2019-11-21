# $FreeBSD$

PORTNAME=	wlrobs
PORTVERSION=	s20191120
DISTVERSIONSUFFIX=	-8b4656a90bc7
CATEGORIES=	multimedia
#MASTER_SITES=	https://hg.sr.ht/~scoopta/${PORTNAME}/archive/${DISTVERSIONSUFFIX:S/^-//}${EXTRACT_SUFX}?dummy=/
MASTER_SITES+=	LOCAL/jbeich # https://todo.sr.ht/~sircmpwn/hg.sr.ht/33
DISTNAME=	${PORTNAME}${DISTVERSIONSUFFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland screen capture plugin for obs-studio

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC:H}/COPYING.md

BUILD_DEPENDS=	${LOCALBASE}/include/obs/obs-module.h:multimedia/obs-studio
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 gmake localbase:ldflags
WRKSRC_SUBDIR=	Release
MAKEFILE=	makefile
DATADIR=	${PREFIX}/lib/obs-plugins
PORTDATA=	${PORTNAME}.so

post-patch:
	@${REINPLACE_CMD} -e 's/ -O3//' \
		-e '/-shared/!s/gcc/$$(CC) $$(CFLAGS)/' \
		-e '/-shared/s/gcc/$$(CC) $$(LDFLAGS)/' \
		${WRKSRC}/makefile \
		${WRKSRC}/proto/subdir.mk \
		${WRKSRC}/src/subdir.mk

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.so \
		${STAGEDIR}${DATADIR}/${PORTNAME}.so

.include <bsd.port.mk>
