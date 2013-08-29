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

USE_QT4=	corelib gui network xml qmake_build moc_build uic_build rcc_build
USE_KDE4=	kdehier
QMAKE_ARGS=	PREFIX=${PREFIX} KDE4_PREFIX=${KDE4_PREFIX}
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
