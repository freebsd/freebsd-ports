# New ports collection makefile for:	libmediawiki
# Date created:				2012-05-12
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libmediawiki
PORTVERSION=	2.7.0
CATEGORIES=	net kde
MASTER_SITES=	SF/digikam/digikam/${PORTVERSION}
DISTNAME=	digikam-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 library for accessing MediaWiki sites

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/extra/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s|$${LIB_INSTALL_DIR}|libdata|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
