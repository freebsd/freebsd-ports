PORTNAME=	plasmatube
DISTVERSION=	23.01.0
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/plasma-mobile/${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Elegant user interface for YouTube
WWW=		https://apps.kde.org/plasmatube/

LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		cmake kde:5 localbase:ldflags pkgconfig qt:5 tar:xz
USE_KDE=	config ecm i18n kirigami2
USE_QT=		core declarative gui network quickcontrols2 svg testlib \
		widgets xml \
		buildtools:build qmake:build

.include <bsd.port.mk>
