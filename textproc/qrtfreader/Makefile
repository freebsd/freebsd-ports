PORTNAME=	qrtfreader
PORTVERSION=	1.0.0
CATEGORIES=	textproc kde
MASTER_SITES=	KDE/stable/qrtfreader

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for reading Rtf documents
WWW=		https://invent.kde.org/libraries/qrtfreader

USES=		cmake kde:6 qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base
USE_LDCONFIG=	yes

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

.include <bsd.port.mk>
