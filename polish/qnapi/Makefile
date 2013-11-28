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

RUN_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip

USES=		qmake
USE_QT4=	corelib gui network xml moc_build uic_build rcc_build
USE_KDE4=	kdehier
PLIST_SUB=	KDE4=${KDE4_PREFIX:S|${LOCALBASE}/||}
QMAKE_ARGS=	KDE4_PREFIX=${KDE4_PREFIX}
INSTALLS_ICONS=	yes

PORTDOCS=	ChangeLog README.pl COPYRIGHT

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|/usr/share/icons/||g' \
		${WRKSRC}/doc/qnapi.desktop \
		${WRKSRC}/doc/qnapi-download.desktop \
		${WRKSRC}/doc/qnapi-download.schemas

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|g} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
