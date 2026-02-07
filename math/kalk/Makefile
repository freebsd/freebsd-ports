PORTNAME=	kalk
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	math kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kalk is a convergent calculator for Plasma
WWW=		https://apps.kde.org/kalk

LICENSE=	GPLv3+

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libqalculate.so:math/libqalculate

USES=		bison cmake desktop-file-utils gettext kde:6 pkgconfig qt:6 \
		tar:xz
USE_KDE=	config coreaddons i18n kirigami2 unitconversion \
		ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
