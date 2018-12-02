# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quantumstyle
DISTVERSION=	rc6
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	http://saidlankri.free.fr/ \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	qt4-style-
DISTNAME=	QuantumStyle-${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	SVG themeable style for Qt 4 and KDE

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake qt:4
USE_QT=		corelib gui svg rcc_build uic_build moc_build

WRKSRC=		${WRKDIR}/QuantumStyle

PLIST_FILES=	${QT_PLUGINDIR_REL}/styles/libquantumstyle.so

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${QT_PLUGINDIR_REL}/styles/
	${INSTALL_PROGRAM} ${WRKSRC}/style/libquantumstyle.so ${STAGEDIR}${PREFIX}/${QT_PLUGINDIR_REL}/styles/

.include <bsd.port.mk>
