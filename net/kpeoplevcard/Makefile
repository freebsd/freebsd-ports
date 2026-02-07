PORTNAME=	kpeoplevcard
DISTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	net kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Datasource plugin for KPeople to read vCard files
WWW=		https://github.com/KDE/kpeoplevcard

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	contacts coreaddons i18n people \
		ecm:build
USE_QT=		core gui widgets \
		buildtools:build qmake:build testlib:build

PLIST_FILES=	lib/cmake/KF5PeopleVCard/KF5PeopleVCardConfig.cmake \
		${QT_PLUGINDIR}/kpeople/datasource/KPeopleVCard.so

.include <bsd.port.mk>
