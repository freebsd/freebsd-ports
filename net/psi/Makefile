# New ports collection makefile for:	psi
# Date created:		Wed May  1 20:27:23 NZST 2002
# Whom:			jonc@chen.org.nz
#
# $FreeBSD$
#

PORTNAME=	psi
PORTVERSION=	0.8.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jonc@chen.org.nz

LIB_DEPENDS+=	qssl.0:${PORTSDIR}/devel/qssl

HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_QT_VER=	3
CONFIGURE_ENV=	QTDIR=${X11BASE}
CONFIGURE_ARGS=	-p ${PREFIX}
MAKE_ARGS+=	QTDIR=${X11BASE} \
		CFLAGS="-pipe -pthread -D_THREAD_SAFE -DQT_NO_DEBUG -DQT_THREAD_SUPPORT"
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src

.include <bsd.port.mk>
