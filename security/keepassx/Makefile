# New ports collection makefile for:	keepassx
# Date created:	   18 September 2006
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	KeePassX
PORTVERSION=	0.2.2
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Cross Platform Password Manager

WRKSRC=		${WRKDIR}/${PORTNAME:L}-${PORTVERSION}

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build qt3support_build corelib gui xml
HAS_CONFIGURE=	yes

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} \
		INCLUDEPATH+=${X11BASE}/include LIBS+=-L${X11BASE}/lib \
		keepass.pro

.include <bsd.port.mk>
