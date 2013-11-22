# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phase
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/ \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	qt4-style-
DISTNAME=	11402-phase-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Widget style for Qt 4 and KDE 4

LICENSE=	MIT

USES=		qmake
USE_BZIP2=	yes
USE_QT4=	corelib gui moc_build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	${QT_PLUGINDIR_REL}/styles/libphasestyle.so
PLIST_DIRSTRY=	${QT_PLUGINDIR_REL}/styles

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${QT_PLUGINDIR_REL}/styles/
	${INSTALL_PROGRAM} ${WRKSRC}/libphasestyle.so ${STAGEDIR}${PREFIX}/${QT_PLUGINDIR_REL}/styles/

.include <bsd.port.mk>
