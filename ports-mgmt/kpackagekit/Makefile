# $FreeBSD$

PORTNAME=	KPackageKit
PORTVERSION=	0.6.3.3
PORTREVISION=	7
CATEGORIES=	ports-mgmt sysutils kde
MASTER_SITES=	http://opendesktop.org/CONTENT/content-files/
DISTNAME=	84745-${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE interface for PackageKit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Skipped for more than 5 years
EXPIRATION_DATE=	2017-09-27

LIB_DEPENDS=	libpackagekit-qt.so:ports-mgmt/packagekit-qt4

USES=		cmake gettext kde:4 pkgconfig tar:bzip2
USE_KDE=	automoc4 kdelibs
USE_QT4=	moc_build qmake_build rcc_build uic_build
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:tl}-${PORTVERSION}

.include <bsd.port.mk>
