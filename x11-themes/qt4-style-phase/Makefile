# New ports collection makefile for:	qt4-style-phase
# Date created:		26 Nov 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phase
PORTVERSION=	0.8
CATEGORIES=	x11-themes
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/ \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	qt4-style-
DISTNAME=	11402-phase-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Widget style for Qt 4 and KDE 4

LICENSE=	MIT

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui qmake_build moc_build
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	${QT_PLUGINDIR_REL}/styles/libphasestyle.so
PLIST_DIRSTRY=	${QT_PLUGINDIR_REL}/styles

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS}

do-install:
	${MKDIR} ${PREFIX}/${QT_PLUGINDIR_REL}/styles/
	${INSTALL_PROGRAM} ${WRKSRC}/libphasestyle.so ${PREFIX}/${QT_PLUGINDIR_REL}/styles/

.include <bsd.port.mk>
