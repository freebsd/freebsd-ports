# $FreeBSD$

PORTNAME=	l10n
DISTVERSION=	${QT4_VERSION}
CATEGORIES=	misc
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt localized messages

USE_QT4=	linguist_build
QT_DIST=	yes

EXTRACT_AFTER_ARGS+=	--include '${DISTNAME}/translations'

EXTRA_PATCHES=	# empty

do-build:
	${QT_BINDIR}/lrelease${_QT_BINSUFX} ${WRKSRC}/translations/*.ts

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${QT_L10NDIR_REL}
	${INSTALL_DATA} ${WRKSRC}/translations/*.qm ${STAGEDIR}${PREFIX}/${QT_L10NDIR_REL}

.include <bsd.port.mk>
