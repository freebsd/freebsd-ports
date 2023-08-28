PORTNAME=	kpkpass
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library to deal with Apple Wallet pass files
WWW=		https://www.kde.org/

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 \
		shared-mime-info tar:xz
USE_KDE=	archive ecm:build
USE_QT=		core gui testlib \
		buildtools:build qmake:build

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
