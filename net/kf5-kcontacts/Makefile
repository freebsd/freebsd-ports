# $FreeBSD$

PORTNAME=	kcontacts
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE api to manage contact information

LICENSE=	LGPL21

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	ecm codecs config coreaddons i18n
USE_QT=		core dbus gui \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

CONFLICTS_INSTALL=	kcontacts-1*

.include <bsd.port.mk>
