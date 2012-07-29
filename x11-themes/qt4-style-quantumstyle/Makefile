# New ports collection makefile for:	qt4-style-quantumstyle
# Date created:		26 Nov 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quantumstyle
DISTVERSION=	rc6
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://saidlankri.free.fr/ \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	qt4-style-
DISTNAME=	QuantumStyle-${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	SVG themeable style for Qt 4 and KDE

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_QT4=	corelib gui svg qmake_build rcc_build uic_build moc_build
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/QuantumStyle

PLIST_FILES=	${QT_PLUGINDIR_REL}/styles/libquantumstyle.so
PLIST_DIRSTRY=	${QT_PLUGINDIR_REL}/styles

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS}

do-install:
	${MKDIR} ${PREFIX}/${QT_PLUGINDIR_REL}/styles/
	${INSTALL_PROGRAM} ${WRKSRC}/style/libquantumstyle.so ${PREFIX}/${QT_PLUGINDIR_REL}/styles/

.include <bsd.port.mk>
