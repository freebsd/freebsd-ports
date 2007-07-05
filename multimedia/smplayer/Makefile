# New ports collection makefile for:	smplayer
# Date created:				13 Jun, 2007
# Whom:	Diego Depaoli <trebestie@gmail.com> and Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	smplayer
DISTVERSION=	0.5.0
CATEGORIES=	multimedia audio kde
MASTER_SITES=	SF

MAINTAINER=	relaxbsd@gmail.com
COMMENT?=	A complete front-end based on QT3 for mplayer

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		${LOCALBASE}/share/smplayer/themes:${PORTSDIR}/multimedia/smplayer-themes

.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == "-qt4"
USE_QT_VER=	4
QT_COMPONENTS=	qmake porting moc uic qt3support uic3 corelib gui

ALL_TARGET=	prep src/smplayer
.else
USE_QT_VER=	3

CONFLICTS?=	smplayer-qt4-[0-9]*

BUILD_DEPENDS+=	qmake:${PORTSDIR}/devel/qmake

QMAKE=		${QT_PREFIX}/bin/qmake

MAKE_ENV+=	QTDIR=${QT_PREFIX} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

ALL_TARGET=	src/smplayer

.if defined(WITH_KDE)
USE_KDELIBS_VER=3
MAKE_ARGS+=	KDE_SUPPORT=1
.endif
.endif

USE_GMAKE=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	Changelog Configurable_shortcuts.txt Install.txt \
		Copying.txt Not_so_obvious_things.txt Translations.txt \
		Icon_themes.txt Readme.txt

post-patch:
	@${REINPLACE_CMD} -e 's|qmake|${QMAKE}|g' \
		-e 's|PREFIX=/usr/local|PREFIX=${PREFIX}|g' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
