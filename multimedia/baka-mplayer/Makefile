# $FreeBSD$

PORTNAME=	baka-mplayer
DISTVERSION=	2.0.1
CATEGORIES=	multimedia audio

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Qt 5 multimedia player based on libmpv

LICENSE=	GPLv2

LIB_DEPENDS=	libmpv.so:${PORTSDIR}/multimedia/mpv

USE_GITHUB=	yes
GH_ACCOUNT=	u8sand
GH_PROJECT=	Baka-MPlayer
GH_TAGNAME=	v${DISTVERSION}
GH_COMMIT=	a76ef8d

USES=		compiler:c++11-lib pkgconfig qmake
USE_QT5=	qmake_build buildtools_build gui network svg widgets x11extras
QMAKE_SOURCE_PATH=${WRKSRC}/src
QMAKE_ARGS=	lupdate="${LUPDATE}" lrelease="${LRELEASE}" \
		MEDIADIR="${PREFIX}/share/icons/hicolor/scalable/apps"
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS NLS NOTO
OPTIONS_SUB=	yes

NLS_USE=	QT5=linguisttools_build
NLS_QMAKE_ON=	CONFIG+="install_translations"
NOTO_DESC=	Original look with Noto Sans font
NOTO_RUN_DEPENDS=	noto>0:${PORTSDIR}/x11-fonts/noto

post-patch:
	${REINPLACE_CMD} '/^Comment/s,=.*,=${COMMENT},' \
		${WRKSRC}/etc/${PORTNAME}.desktop
	${REINPLACE_CMD} -e 's,/usr,${PREFIX},' \
		-e 's,share/man,man,' \
		${WRKSRC}/src/Baka-MPlayer.pro

post-install:
# XXX vendor install_man is too broken
	${INSTALL_MAN} ${WRKSRC}/etc/doc/${PORTNAME}.man \
		${STAGEDIR}${MAN1PREFIX}/man/man1/${PORTNAME}.1
	@(cd ${WRKSRC}/etc/logo && for f in *.png; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/$${f%.*}/apps; \
		${INSTALL_DATA} -v $$f \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/$${f%.*}/apps/${PORTNAME}.$${f#*.}; \
	done)

.include <bsd.port.mk>
