# $FreeBSD$

PORTNAME=	baka-mplayer
DISTVERSION=	2.0.0
CATEGORIES=	multimedia audio

MAINTAINER=	jbeich@vfemail.net
COMMENT=	Qt 5 multimedia player based on libmpv

LICENSE=	GPLv2

LIB_DEPENDS=	libmpv.so:${PORTSDIR}/multimedia/mpv

USE_GITHUB=	yes
GH_ACCOUNT=	u8sand
GH_PROJECT=	Baka-MPlayer
GH_TAGNAME=	v${DISTVERSION}
GH_COMMIT=	0393546

USES=		compiler:c++11-lib pkgconfig qmake
USE_QT5=	qmake_build buildtools_build gui network svg_run widgets x11extras
QMAKE_ARGS=	src/${GH_PROJECT}.pro
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NOTO
NOTO_DESC=	Original look with Noto Sans font
NOTO_RUN_DEPENDS=	noto>0:${PORTSDIR}/x11-fonts/noto

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} '/^Comment/s,=.*,=${COMMENT},' \
		${WRKSRC}/arch/${PORTNAME}.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/etc/doc/${PORTNAME}.man \
		${STAGEDIR}${MAN1PREFIX}/man/man1/${PORTNAME}.1
	${INSTALL_DATA} ${WRKSRC}/arch/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/etc/doc/${PORTNAME}.md \
		${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}
.endif
	@cd ${WRKSRC}/etc/logo && for f in *.png; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/$${f%.*}/apps; \
		${INSTALL_DATA} -v $$f \
	${STAGEDIR}${PREFIX}/share/icons/hicolor/$${f%.*}/apps/${PORTNAME}.$${f#*.}; \
	done
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/etc/logo/${PORTNAME}-icon.svg \
		${STAGEDIR}${PREFIX}/share/icons/scalable/apps/${PORTNAME}.svg

.include <bsd.port.mk>
