# $FreeBSD$

PORTNAME=	kwallet-pam
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	security kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 KWallet PAM Integration

BUILD_DEPEMDS=	socat:net/socat
RUN_DEPEMDS=	socat:net/socat
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

USES=		cmake cpe gettext kde:5 qt:5 tar:xz
USE_KDE=	ecm wallet
USE_QT=		gui \
		buildtools_build qmake_build

.include <bsd.port.mk>
