PORTNAME=	attica
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits kde kde-frameworks

PATCH_SITES=	https://invent.kde.org/frameworks/attica/-/commit/
PATCHFILES=	24fc57ece156aaad1bbb86adba2e16c8e89dc6ff.diff:-p1 \
		04bd6dcd39895ce3637145e719c3c427bc7f1ca1.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Open Collaboration Services API library KDE5 version

# The sources are LGPL21 or LGPL3 or later-version-approved-by-KDE,
# so use the OR of existing license versions. COPYING is LGPL21.
LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

USES=		cmake compiler:c++11-lib kde:5 pathfix qt:5 tar:xz
USE_KDE=	ecm_build
USE_QT=		core network \
		buildtools_build qmake_build testlib_build 

.include <bsd.port.mk>
