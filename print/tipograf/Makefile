# ex:ts=8
# Ports collection makefile for:	tipograf
# Date created:			Oct 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tipograf
PORTVERSION=	0.5
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	http://www.falk-henrich.de/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for a2ps

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	a2ps:${PORTSDIR}/print/a2ps-letter
RUN_DEPENDS=	a2ps:${PORTSDIR}/print/a2ps-letter

USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt-dir=${QT_PREFIX}

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e \
		's|-Wall -O0|@CXXFLAGS@|g' ${WRKSRC}/src/Makefile.in

pre-build:
.for file in about.h firststart.h help.h tipograf.h
	@cd ${WRKSRC}/src && ${RM} -f ${file} && ${GMAKE} ${file}
.endfor

.include <bsd.port.mk>
