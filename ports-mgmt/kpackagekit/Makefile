# New ports collection makefile for:	kpackagekit
# Date created:				11 May 2010
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	KPackageKit
PORTVERSION=	0.6.3.3
PORTREVISION=	2
CATEGORIES=	ports-mgmt sysutils kde
MASTER_SITES=	http://opendesktop.org/CONTENT/content-files/
DISTNAME=	84745-${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE interface for PackageKit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	packagekit-qt.14:${PORTSDIR}/ports-mgmt/packagekit-qt4

USE_BZIP2=	yes
USE_GNOME=	pkgconfig
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
USE_QT4=	moc_build qmake_build rcc_build uic_build
USES=		cmake gettext
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:L}-${PORTVERSION}

.include <bsd.port.mk>
