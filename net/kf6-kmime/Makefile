PORTNAME=	kmime
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	net kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for handling MIME data

CONFLICTS=	kmime # net/kmime

USES=		cmake kde:6 qt:6 tar:xz
USE_KDE=	codecs \
		ecm:build
USE_QT=		base \
		tools:build

.include <bsd.port.mk>
