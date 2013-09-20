# Created by: Manuel Giraud <manuel.giraud@gmail.com>
# $FreeBSD$

PORTNAME=	profont
PORTVERSION=	400
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.tobiasjung.net/dl/
DISTNAME=	${PORTNAME}-x11

MAINTAINER=	manuel.giraud@gmail.com
COMMENT= 	Profont - The ultimate programming font.

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig

FONTDIR=	lib/X11/fonts/${PORTNAME}
PLIST_SUB+=	FONTDIR=${FONTDIR}

NO_STAGE=	yes
do-build:
	${GZIP_CMD} ${WRKSRC}/*.pcf

do-install:
	${MKDIR} ${LOCALBASE}/${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${LOCALBASE}/${FONTDIR}

post-install:
	@cd ${LOCALBASE}/${FONTDIR}; mkfontdir
	@${CP} ${LOCALBASE}/${FONTDIR}/fonts.dir ${LOCALBASE}/${FONTDIR}/fonts.scale || true
	@command fc-cache -f -v ${LOCALBASE}/${FONTDIR} || true

.include <bsd.port.mk>
