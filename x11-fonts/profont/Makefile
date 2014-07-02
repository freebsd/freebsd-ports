# Created by: Manuel Giraud <manuel.giraud@gmail.com>
# $FreeBSD$

PORTNAME=	profont
PORTVERSION=	400
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.tobiasjung.net/dl/
DISTNAME=	${PORTNAME}-x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ultimate programming font

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

FONTDIR=	lib/X11/fonts/${PORTNAME}
PLIST_SUB+=	FONTDIR=${FONTDIR}

do-build:
	${GZIP_CMD} ${WRKSRC}/*.pcf

do-install:
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${STAGEDIR}${LOCALBASE}/${FONTDIR}
	(cd ${STAGEDIR}${LOCALBASE}/${FONTDIR}; mkfontdir; mkfontscale)

.include <bsd.port.mk>
