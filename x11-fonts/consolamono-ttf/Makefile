# $FreeBSD$

PORTNAME=	consolamono-ttf
PORTVERSION=	20130127
CATEGORIES=	x11-fonts
MASTER_SITES=	http://openfontlibrary.org/assets/downloads/consolamono/61cc2afcc4eca96efe7c6ebf178d39df/
DISTNAME=	consolamono

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Monospace font created for programming, text editors and terminal-use

LICENSE=	OFL11

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USES=		zip

FONTDIR=	lib/X11/fonts/ConsolaMono
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB=	FONTDIR=${FONTDIR}
SUB_FILES=	pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}
WRKSRC=		${WRKDIR}/Consola\ Mono

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
