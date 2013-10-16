# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	float
PORTVERSION=	0.1a2
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/ \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	qt4-style-
DISTNAME=	54477-floatstyle-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Style for Qt 4 and KDE

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_QT4=	corelib gui qmake_build moc_build rcc_build

WRKSRC=		${WRKDIR}/floatstyle-${PORTVERSION}

PLIST_FILES=	${QT_PLUGINDIR_REL}/styles/libfloatstyle.so
PLIST_DIRSTRY=	${QT_PLUGINDIR_REL}/styles

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${QT_PLUGINDIR_REL}/styles/
	${INSTALL_PROGRAM} ${WRKSRC}/libfloatstyle.so ${STAGEDIR}${PREFIX}/${QT_PLUGINDIR_REL}/styles/

.include <bsd.port.mk>
