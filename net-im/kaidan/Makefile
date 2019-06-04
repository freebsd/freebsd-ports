# $FreeBSD$

PORTNAME=	kaidan
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0-rc1
CATEGORIES=	net-im kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	 A user-friendly XMPP client for every device

LIB_DEPENDS=	libqxmpp.so:net-im/qxmpp-qt5

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 pkgconfig qt:5
USE_KDE=	ecm kirigami2
USE_QT=		core declarative gui network quickcontrols2 sql svg widgets xml \
		buildtools_build qmake_build
USE_GITHUB=	yes
GH_ACCOUNT=	KDE

.include <bsd.port.mk>
