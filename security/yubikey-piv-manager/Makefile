# $FreeBSD$

PORTNAME=	yubikey-piv-manager
PORTVERSION=	1.2.1
#PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/yubikey-piv-manager/Releases/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	YubiKey PIV Manager

LICENSE=	GPLv3+

RUN_DEPENDS=	pyside${PYTHON_PKGNAMESUFFIX}>=1.0.9:devel/pyside \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto \
		yubico-piv-tool:security/yubico-piv-tool

NO_ARCH=	yes
USES=		python:2
USE_PYTHON=	autoplist distutils

PLIST_FILES+=	man/man1/pivman.1.gz \
		share/applications/pivman.desktop \
		share/pixmaps/yubikey-piv-manager.png

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/resources/pivman.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/resources/yubikey-piv-manager.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
