# New ports collection makefile for:	speedcrunch
# Date created:		27 Jul 2007
# Whom:                	Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	speedcrunch
DISTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A desktop calculator for power users

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build gui
USE_CMAKE=	yes
CMAKE_SOURCE_PATH=	src
CMAKE_USE_PTHREAD=	yes

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
