# $FreeBSD$

PORTNAME=	baka-mplayer
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.4
PORTREVISION=	8
CATEGORIES=	multimedia audio

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Qt 5 multimedia player based on libmpv

LICENSE=	GPLv2

LIB_DEPENDS=	libmpv.so:multimedia/mpv

USE_GITHUB=	yes
GH_ACCOUNT=	u8sand
GH_PROJECT=	Baka-MPlayer

USES=		compiler:c++11-lib pkgconfig qmake qt:5
USE_QT=		qmake_build buildtools_build gui network svg widgets x11extras
QMAKE_SOURCE_PATH=${WRKSRC}/src
QMAKE_ARGS=	lupdate="${LUPDATE}" lrelease="${LRELEASE}"

OPTIONS_DEFINE=	DOCS NLS NOTO
OPTIONS_SUB=	yes

NLS_USES=	qt:5
NLS_USE=	QT=linguisttools_build
NLS_QMAKE_ON=	CONFIG+="install_translations"
NOTO_DESC=	Original look with Noto Sans font
NOTO_RUN_DEPENDS=	noto>0:x11-fonts/noto

post-patch:
	${REINPLACE_CMD} '/^Comment/s,=.*,=${COMMENT},' \
		${WRKSRC}/etc/${PORTNAME}.desktop
	${REINPLACE_CMD} -e 's,/usr,${PREFIX},' \
		-e 's,share/man,man,' \
		${WRKSRC}/src/Baka-MPlayer.pro

post-install:
	@(cd ${WRKSRC}/etc/logo && for f in *.png; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/$${f%.*}/apps; \
		${INSTALL_DATA} -v $$f \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/$${f%.*}/apps/${PORTNAME}.$${f#*.}; \
	done)

.include <bsd.port.mk>
