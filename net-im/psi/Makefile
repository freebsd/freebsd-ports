# New ports collection makefile for:	psi
# Date created:		Wed May  1 20:27:23 NZST 2002
# Whom:			jonc@chen.org.nz
#
# $FreeBSD$
#

PORTNAME=	psi
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	eugos@gmx.net
COMMENT=	A Qt-based Jabber client

RUN_DEPENDS=	${X11BASE}/lib/plugins/crypto/libqca-tls.so:${PORTSDIR}/security/qca-tls

HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_QT_VER=	3
CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS=	--prefix=${PREFIX} --qtdir=${X11BASE} --disable-kde
MAKE_ARGS+=	QTDIR=${X11BASE} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

post-install:
	${STRIP_CMD} ${PREFIX}/bin/psi

.include <bsd.port.mk>
