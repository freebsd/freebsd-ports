# ex:ts=8
# Ports collection makefile for:	tipograf
# Date created:			Oct 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tipograf
PORTVERSION=	0.5
CATEGORIES=	print
MASTER_SITES=	http://www.falk-henrich.de/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for a2ps

BUILD_DEPENDS=	a2ps:${PORTSDIR}/print/a2ps-letter
RUN_DEPENDS=	a2ps:${PORTSDIR}/print/a2ps-letter

USE_QT_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-qt-dir=${QT_PREFIX}

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e \
		's|-Wall -O0|@CXXFLAGS@|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
