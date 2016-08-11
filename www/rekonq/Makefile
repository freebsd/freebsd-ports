# $FreeBSD$

PORTNAME=	rekonq
PORTVERSION=	2.4.2
PORTREVISION=	3
CATEGORIES=	www kde
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:C,\..*,.0,}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Lightweight KDE browser based on WebKit

USES=		cmake:outsource gettext tar:xz
USE_KDE4=	kdelibs automoc4
USE_QT4=	script webkit \
		moc_build qmake_build rcc_build uic_build

OPTIONS_DEFINE=	OPERA NEPOMUK
OPTIONS_DEFAULT=	NEPOMUK

OPERA_DESC=	Support for Opera Sync service
OPERA_LIB_DEPENDS=	libqca.so:devel/qca \
			libqoauth.so:net/qoauth
OPERA_CMAKE_OFF=	-DWITH_QCA2=off \
			-DWITH_QtOAuth=off

NEPOMUK_DESC=	Bookmarks tagging via Nepomuk
NEPOMUK_USE=	KDE4=nepomuk-core
NEPOMUK_CMAKE_OFF=	-DWITH_NepomukCore=off

post-patch:
	${REINPLACE_CMD} -e \
		's,FIND_PACKAGE(NepomukCore,MACRO_OPTIONAL_FIND_PACKAGE(NepomukCore,' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
