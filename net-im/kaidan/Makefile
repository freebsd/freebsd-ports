# $FreeBSD$

PORTNAME=	kaidan
DISTVERSION=	0.4.1
PORTREVISION=	4
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	User-friendly XMPP client for every device

LIB_DEPENDS=	libqxmpp.so:net-im/qxmpp-qt5

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	ecm kirigami2
USE_QT=		core declarative gui network quickcontrols2 sql svg widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
