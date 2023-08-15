PORTNAME=	libmediawiki
DISTVERSION=	5.38.0
PORTREVISION=	1
CATEGORIES=	net kde
MASTER_SITES=	KDE/stable/${PORTNAME}
DIST_SUBDIR=	KDE/digikam

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library for accessing MediaWiki sites
WWW=		https://www.digikam.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	coreaddons \
		ecm:build
USE_QT=		core network testlib \
		buildtools:build qmake:build

.include <bsd.port.mk>
