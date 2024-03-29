PORTNAME=	${GH_ACCOUNT:tl}
PORTVERSION=	3.5.5
PORTREVISION=	2
CATEGORIES=	multimedia

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	HDR-aware multimedia file converter
WWW=		https://github.com/CineEncoder/cine-encoder

LICENSE=	GPLv3

LIB_DEPENDS=	libmediainfo.so:multimedia/libmediainfo
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		mkvpropedit:multimedia/mkvtoolnix

USES=		pkgconfig qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	CineEncoder
GH_PROJECT=	cine-encoder
USE_QT=		buildtools:build qmake:build core gui multimedia \
		network svg widgets x11extras
USE_XORG=	x11 xext

PLIST_FILES=	bin/cine_encoder share/man/man1/cine-encoder.1.gz \
		share/applications/cine-encoder.desktop \
		share/icons/hicolor/64x64/apps/cine-encoder.png \
		share/sounds/cine-encoder.wav
PORTDOCS=	ABOUT AUTHORS

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/#if defined/s,linux,${OPSYS},' \
		${WRKSRC}/app/encoderstream.h

do-configure:
	cd ${CONFIGURE_WRKSRC} && ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS} \
		app/cine_encoder.pro CONFIG+=qtquickcompiler

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/builddir/cine_encoder \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/distros/debian/cine-encoder.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
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
