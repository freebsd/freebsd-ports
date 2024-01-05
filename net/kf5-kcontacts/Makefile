PORTNAME=	kcontacts
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTEPOCH=	1
CATEGORIES=	net kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE api to manage contact information

LICENSE=	LGPL21

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	codecs config coreaddons i18n \
		ecm:build
USE_QT=		core gui \
		buildtools:build qmake:build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
