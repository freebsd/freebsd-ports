# $FreeBSD$

PORTNAME=	kaidan
DISTVERSION=	0.7.0
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/unstable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	User-friendly XMPP client for every device

LIB_DEPENDS=	libqxmpp.so:net-im/qxmpp-qt5 \
		libZXing.so:textproc/zxing-cpp

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 \
		pkgconfig qt:5 tar:xz
USE_KDE=	ecm kirigami2 notifications
USE_QT=		core dbus declarative gui location multimedia network \
		quickcontrols2 sql svg widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
