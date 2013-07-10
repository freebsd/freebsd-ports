# Created by: Eric Kjeldergaard <kjelderg@gmail.com>
# $FreeBSD$

PORTNAME=	kiax
PORTVERSION=	0.8.51
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src_bin.tar.gz/${PORTVERSION}%20%28Ariana%29
DISTNAME=	kiax-${PORTVERSION}-src

MAINTAINER=	kjelderg@gmail.com
COMMENT=	Asterisk (IAX) client written in QT for KDE

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake \
		lrelease:${PORTSDIR}/x11-toolkits/qt33

USES=		gmake
MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=	yes
USE_QT_VER=	3

CONFIGURE_ENV+=	\
      QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		EXPR_COMPAT=yes
MAKE_ARGS+=	QTDIR=${QT_PREFIX} \
      QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

.include <bsd.port.mk>
