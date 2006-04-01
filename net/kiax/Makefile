# New ports collection makefile for:   kiax
# Date created:        Sat Jun 25 16:31:30 UTC 2005
# Whom:                Eric Kjeldergaard <kjelderg@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	kiax
PORTVERSION=	0.8.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kjelderg@gmail.com
COMMENT=	An Asterisk (IAX) client written in QT for KDE

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake \
	lrelease:${PORTSDIR}/x11-toolkits/qt33

USE_GMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=	yes
USE_QT_VER=	3

CONFIGURE_ENV+=	QTDIR=${X11BASE} \
      QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		EXPR_COMPAT=yes
MAKE_ARGS+=	QTDIR=${X11BASE} \
      QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile
.endif

post-patch:
.if ${OSVERSION} < 500000
	${REINPLACE_CMD} 's/stdint\.h/inttypes.h/' ${WRKSRC}/lib/spandsp/plc.h
.endif

.include <bsd.port.post.mk>
