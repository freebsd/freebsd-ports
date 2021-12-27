PORTNAME=	libmediawiki
DISTVERSION=	5.37.0
PORTREVISION=	3
CATEGORIES=	net kde
MASTER_SITES=	KDE/stable/${PORTNAME}
DIST_SUBDIR=	KDE/digikam

PATCH_SITES=	https://invent.kde.org/libraries/libmediawiki/-/commit/
PATCHFILES=	2ac89aaca0bb5daa9a6e11b055d4fc236b1613be.diff:-p1 \
		7c79dae079d20b46d05462ed9f5b3cfae78f420a.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library for accessing MediaWiki sites

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	coreaddons ecm
USE_QT=		core network testlib \
		buildtools_build qmake_build

.include <bsd.port.mk>
