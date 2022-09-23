PORTNAME=	kwallet-pam
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	security kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 KWallet PAM Integration
WWW=		https://www.kde.org/plasma-desktop

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

USES=		cmake gettext kde:5 qt:5 tar:xz
USE_KDE=	ecm wallet
USE_QT=		gui \
		buildtools:build qmake:build

post-patch:
	@${REINPLACE_CMD} -e 's,socat,nc,' -e 's,/security,,' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} 's,/usr/bin/kwalletd,${LOCALBASE}/bin/kwalletd,' \
		${WRKSRC}/pam_kwallet.c

.include <bsd.port.mk>
