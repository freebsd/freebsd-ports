# New ports collection makefile for:	kwebkitpart
# Date created:				4 March 2010
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kwebkitpart
PORTVERSION=	1.2.0
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	avilla

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Web browser component for KDE SC based on QtWebKit

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT_VER=	4
QT_COMPONENTS=	designer gui webkit \
		moc_build qmake_build rcc_build uic_build
USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
