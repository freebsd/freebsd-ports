# New ports collection makefile for:	spassgen
# Date created:				29 Jul 2004
# Whom:					Rashid N. Achilov <shelton@granch.ru>
#
# $FreeBSD$
#

PORTNAME=	spassgen
PORTVERSION=	1.5
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	spassgen

MAINTAINER=	shelton@granch.ru
COMMENT=	Qt GUI secure password generator

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
QMAKE_LOCATION=	${LOCALBASE}/bin

MAKE_ENV+=	QTDIR="${QT_PREFIX}"
DOCSDIR=	share/doc/HTML/en/${PORTNAME}

pre-build:
	(cd ${WRKSRC}; \
	  ${QMAKE_LOCATION}/qmake -project spassgen.pro; \
	  ${SETENV} QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
	 ${QMAKE_LOCATION}/qmake)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spassgen ${PREFIX}/bin
.for i in 128x128 16x16 32x32 48x48 64x64
	${MKDIR} ${PREFIX}/share/icons/hicolor/${i}/apps
	${INSTALL_DATA} ${WRKSRC}/icons/${i}/password.png ${PREFIX}/share/icons/hicolor/${i}/apps
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCSDIR}
.for i in AUTHORS LICENCE README TODO INSTALL
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
