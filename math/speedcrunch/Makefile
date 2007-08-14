# New ports collection makefile for:	speedcrunch
# Date created:		27 Jul 2007
# Whom:                	Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	speedcrunch
DISTVERSION=	0.8
CATEGORIES=	math
MASTER_SITES=	http://speedcrunch.googlecode.com/files/

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	A desktop calculator for power users

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

USE_QT_VER=	4
QT_COMPONENTS=	qmake corelib moc gui rcc
CMAKE_ARGS=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DCMAKE_C_COMPILER:STRING='${CC}' \
		-DCMAKE_CXX_COMPILER:STRING=${CXX} \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS} -pthread" \
		-DCMAKE_INSTALL_PREFIX=${PREFIX}

MYPORTDOCS=	COPYING ChangeLog HACKING.txt INSTALL.txt LISEZMOI PACKAGERS README \
		TRANSLATORS doc/man.docbook doc/speedcrunch.docbook

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

DESKTOP_ENTRIES=	"SpeedCrunch" \
			"A desktop calculator for power users" \
			"crunch" \
			"speedcrunch" \
			"Qt;KDE;Education;Math;" \
			"false"

post-patch:
	@${REINPLACE_CMD} -e 's|qwindowdefs.h|QtGui/qwindowdefs.h|g' \
		-e 's|qcolor.h|QtGui/qcolor.h|g' \
		-e 's|qfont.h|QtGui/qfont.h|g' \
		-e 's|qrect.h|QtCore/qrect.h|g' \
		-e 's|qstring.h|QtCore/qstring.h|g' \
		-e 's|qstringlist.h|QtCore/qstringlist.h|g' \
		${WRKSRC}/src/settings.h
	@${REINPLACE_CMD} -e 's|crunch\"|speedcrunch\"|g' \
		${WRKSRC}/src/main.cpp

pre-build:
	@(cd ${WRKSRC};	\
	${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/cmake ${CMAKE_ARGS} ${WRKSRC}/src)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/speedcrunch ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/src/crunch.png ${PREFIX}/share/pixmaps
.if !defined(WITHOUT_NLS)
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/src/*.qm ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${MYPORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
