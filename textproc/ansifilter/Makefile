# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	ansifilter
PORTVERSION=	2.16
CATEGORIES=	textproc
MASTER_SITES=	http://www.andre-simon.de/zip/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Customizable ANSI Code Converter

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib gmake tar:bzip2

MAKEFILE=	makefile

PORTDOCS=	ChangeLog.adoc README.adoc
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=		DOCS QT5

QT5_USES=		qmake:norecursive qt:5
QT5_USE=		QT=gui,widgets
QT5_ALL_TARGET=		all all-gui
QT5_PLIST_FILES=	bin/${PORTNAME}-gui
QT5_DESKTOP_ENTRIES=	"ANSIFilter" "" "" "${PORTNAME}-gui" \
			"TextTools;Utility;Qt;" ""

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT5}
CONFIGURE_WRKSRC=	${WRKSRC}/src/qt-gui
QMAKE_SOURCE_PATH=	${CONFIGURE_WRKSRC}/${PORTNAME}-gui.pro
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/QMAKE/s|^|#|' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e \
		's|^CC=|CC?=| ; \
		 s|^CFLAGS=|CXXFLAGS+=| ; \
		 s|-O2|| ; \
		 s|$$(CC)|$$(CXX)| ; \
		 s|$$(CFLAGS)|$$(CXXFLAGS)|' ${WRKSRC}/src/${MAKEFILE}

pre-build:
	@${RM} ${WRKSRC}/src/qt-gui/moc_*.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR})

do-install-QT5-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/qt-gui/${PORTNAME}-gui \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
