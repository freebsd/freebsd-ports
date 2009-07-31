# New ports collection makefile for:   kiax
# Date created:        Sat Jun 25 16:31:30 UTC 2005
# Whom:                Eric Kjeldergaard <kjelderg@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	kiax
PORTVERSION=	0.8.51
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	kiax-${PORTVERSION}-src

MAINTAINER=	kjelderg@gmail.com
COMMENT=	An Asterisk (IAX) client written in QT for KDE

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake \
		lrelease:${PORTSDIR}/x11-toolkits/qt33

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=	yes
USE_QT_VER=	3

CONFIGURE_ENV+=	\
      QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		EXPR_COMPAT=yes
MAKE_ARGS+=	QTDIR=${QT_PREFIX} \
      QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

.include <bsd.port.mk>
