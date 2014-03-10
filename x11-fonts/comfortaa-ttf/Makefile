# $FreeBSD$

PORTNAME=	comfortaa-ttf
PORTVERSION=	2.004
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://openfontlibrary.org/assets/downloads/comfortaa/38318a69b56162733bf82bc0170b7521/
DISTNAME=	comfortaa

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Stylish, modern and free sans-serif true type font

LICENSE=	OFL11

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USES=		zip

FONTDIR=	lib/X11/fonts/Comfortaa
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB=	FONTDIR=${FONTDIR}
SUB_FILES=	pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}
WRKSRC=		${WRKDIR}/Comfortaa

NO_STAGE=	yes
do-build:
	@cd ${WRKSRC}/ && \
		${LOCALBASE}/bin/mkfontscale && \
		${LOCALBASE}/bin/mkfontdir

do-install:
	${MKDIR} ${PREFIX}/${FONTDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.ttf fonts.* ${PREFIX}/${FONTDIR}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
