# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	${GH_ACCOUNT:tl}
PORTVERSION=	3.5.2
CATEGORIES=	multimedia

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	HDR-aware multimedia file converter

LICENSE=	GPLv3

LIB_DEPENDS=	libmediainfo.so:multimedia/libmediainfo
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		mkvpropedit:multimedia/mkvtoolnix

USES=		qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	CineEncoder
GH_PROJECT=	cine-encoder
USE_QT=		buildtools_build qmake_build core gui multimedia \
		network widgets

PLIST_FILES=	bin/cine_encoder man/man1/cine-encoder.1.gz \
		share/applications/cine-encoder.desktop \
		share/icons/hicolor/64x64/apps/cine-encoder.png \
		share/sounds/cine-encoder.wav
PORTDOCS=	ABOUT AUTHORS

OPTIONS_DEFINE=	DOCS

do-configure:
	cd ${CONFIGURE_WRKSRC} && ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS} \
		app/cine_encoder.pro CONFIG+=qtquickcompiler

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cine_encoder ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/distros/debian/cine-encoder.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/share/cine-encoder.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps
	${INSTALL_DATA} ${WRKSRC}/share/cine-encoder.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/sounds
	${INSTALL_DATA} ${WRKSRC}/share/cine-encoder.wav \
		${STAGEDIR}${PREFIX}/share/sounds

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/share/ABOUT ${WRKSRC}/AUTHORS \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
