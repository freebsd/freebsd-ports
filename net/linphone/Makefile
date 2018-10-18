# $FreeBSD$

PORTNAME=	linphone
PORTVERSION=	4.1.1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	https://www.linphone.org/releases/sources/linphoneqt/
DISTNAME=	linphoneqt-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SIP client supporting voice/video calls and text messaging

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbelcard.so:deskutils/belcard \
		liblinphone++.so:net/liblinphone

USES=		cmake:outsource pkgconfig qt:5
USE_QT= 	buildtools_build concurrent core gui linguisttools network \
		qmake_build qml quick quickcontrols2 speech svg testlib widgets

post-patch:
	@${REINPLACE_CMD} 's/LINPHONE_QT_GIT_VERSION/"${PORTVERSION}"/' \
		${WRKSRC}/src/app/AppController.cpp

.include <bsd.port.mk>
