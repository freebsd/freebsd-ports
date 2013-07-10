# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	qnapi
PORTVERSION=	0.1.6.r2
CATEGORIES=	polish multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-rc2

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Qt4 based subtitle downloader

LICENSE=	GPLv2

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip

USES=		gettext iconv
USE_XORG=	ice sm x11 xau xcb xdmcp xext xrender
USE_QT4=	corelib gui network xml qmake_build moc_build uic_build rcc_build
USE_KDE4=	kdehier
QMAKE_ARGS=	PREFIX=${PREFIX} KDE4_PREFIX=${KDE4_PREFIX}
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

MAN1=		qnapi.1
MANCOMPRESSED=	yes
PORTDOCS=	ChangeLog README.pl COPYRIGHT

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} 's|/usr/share/icons/||g' \
		${WRKSRC}/doc/qnapi.desktop \
		${WRKSRC}/doc/qnapi-download.desktop \
		${WRKSRC}/doc/qnapi-download.schemas

pre-build:
	@cd ${WRKSRC} && ${QMAKE} -spec ${QMAKESPEC} ${QMAKEFLAGS} ${QMAKE_ARGS}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
