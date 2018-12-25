# $FreeBSD$

PORTNAME=	rekonq
PORTVERSION=	2.4.2
PORTREVISION=	5
CATEGORIES=	www kde
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:C,\..*,.0,}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight KDE browser based on WebKit

LICENSE=	GPLv3+ GFDL
LICENSE_COMB=	multi

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_GFDL=	${WRKSRC}/COPYING.DOC

USES=		cmake gettext kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		script webkit \
		moc_build qmake_build rcc_build uic_build

OPTIONS_DEFINE=		OPERA NEPOMUK
OPTIONS_DEFAULT=	NEPOMUK

OPERA_DESC=		Support for Opera Sync service
OPERA_LIB_DEPENDS=	libqca.so:devel/qca@qt4 \
			libqoauth.so:net/qoauth
OPERA_CMAKE_OFF=	-DWITH_QCA2=off \
			-DWITH_QtOAuth=off

NEPOMUK_DESC=		Bookmarks tagging via Nepomuk
NEPOMUK_USE=		KDE=nepomuk-core
NEPOMUK_CMAKE_OFF=	-DWITH_NepomukCore=off

post-patch:
	@${REINPLACE_CMD} -e \
		's,FIND_PACKAGE(NepomukCore,MACRO_OPTIONAL_FIND_PACKAGE(NepomukCore,' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
