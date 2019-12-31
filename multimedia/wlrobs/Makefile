# $FreeBSD$

PORTNAME=	wlrobs
PORTVERSION=	s20191230
DISTVERSIONSUFFIX=	-d7294c05b907
CATEGORIES=	multimedia
#MASTER_SITES=	https://hg.sr.ht/~scoopta/${PORTNAME}/archive/${DISTVERSIONSUFFIX:S/^-//}${EXTRACT_SUFX}?dummy=/
MASTER_SITES+=	LOCAL/jbeich # https://todo.sr.ht/~sircmpwn/hg.sr.ht/33
DISTNAME=	${PORTNAME}${DISTVERSIONSUFFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland screen capture plugin for obs-studio

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.md

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libobs.so:multimedia/obs-studio

USES=		compiler:c11 meson pkgconfig
DATADIR=	${PREFIX}/lib/obs-plugins
PORTDATA=	${PORTNAME}.so

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_LIB} ${INSTALL_WRKSRC}/lib${PORTNAME}.so \
		${STAGEDIR}${DATADIR}/${PORTNAME}.so

.include <bsd.port.mk>
