# New ports collection makefile for:	qt4-l10n
# Date created:		2008-12-13
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	l10n
PORTVERSION=	${QT4_VERSION}
CATEGORIES?=	misc
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt translations messages

USE_QT_VER=	4
QT_COMPONENTS=	linguist_build
QT_DIST=	yes
QT_NONSTANDARD=	yes

EXTRACT_AFTER_ARGS+=	| ${TAR} -xf - --include '${DISTNAME}/translations'

do-build:
	${LOCALBASE}/bin/lrelease-qt4 ${WRKSRC}/translations/*.ts

do-install:
	${MKDIR} ${PREFIX}/share/qt4/translations
	${INSTALL_DATA} ${WRKSRC}/translations/*.qm ${PREFIX}/share/qt4/translations

.include <bsd.port.mk>
