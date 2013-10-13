# $FreeBSD$

PORTNAME=	l10n
DISTVERSION=	${QT4_VERSION}
CATEGORIES?=	misc
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt translations messages

USE_QT4=	linguist_build
QT_DIST=	yes
QT_NONSTANDARD=	yes

EXTRACT_AFTER_ARGS+=	--include '${DISTNAME}/translations'

do-build:
	${LOCALBASE}/bin/lrelease-qt4 ${WRKSRC}/translations/*.ts

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/qt4/translations
	${INSTALL_DATA} ${WRKSRC}/translations/*.qm ${STAGEDIR}${PREFIX}/share/qt4/translations

.include <bsd.port.mk>
