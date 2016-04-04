# $FreeBSD$

PORTNAME=	yubikey-personalization-gui
PORTVERSION=	3.1.24
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	security

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Graphical YubiKey personalization tool

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libykpers-1.so:security/ykpers

USE_GITHUB=	yes
GH_ACCOUNT=	Yubico

USES=		pkgconfig qmake
USE_QT4=	corelib gui moc_build rcc_build testlib_build uic_build

PLIST_FILES=	bin/yubikey-personalization-gui

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/yubikey-personalization-gui ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
