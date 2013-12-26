# $FreeBSD$

PORTNAME=	alegreya-sans
PORTVERSION=	20130313
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.huertatipografica.com/free_download/G4oDzW61NXb23OxBa8XL?dummy=

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Humanist sans serif font with a calligraphic feeling

LICENSE=	OFL11

FETCH_BEFORE_ARGS=	-o ${DISTFILES}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

FONTDIR=	${STAGEDIR}${PREFIX}/lib/X11/fonts/${PORTNAME}

do-install:
	${MKDIR} ${FONTDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} *.otf ${FONTDIR}

.include <bsd.port.mk>
