PORTNAME=	kwallet-pam
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	security kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PAM Integration with KWallet - Unlock KWallet when you login

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

USES=		cmake kde:6 pkgconfig qt:6 tar:xz
USE_KDE=	wallet \
		ecm:build
USE_QT=		# dummy

post-patch:
	@${REINPLACE_CMD} -e 's,socat,nc,' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
