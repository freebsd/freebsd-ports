# New ports collection Makefile for:		kphone
# Date created:					2004-07-05
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	kphone
PORTVERSION=	4.0.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.wirlab.net/kphone/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A voice over internet phone

USE_QT_VER=	3
WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	QTDIR="${X11BASE}"

post-patch:
	${REINPLACE_CMD} -e "s,-O3,${CFLAGS} ${PTHREAD_CFLAGS}," ${WRKSRC}/configure
	${REINPLACE_CMD} -e "s,-lresolv,${PTHREAD_LIBS}," ${WRKSRC}/kphone/Makefile.in

do-build:
	cd ${WRKSRC}/dissipate2; ${SETENV} ${MAKE_ENV} ${GMAKE}
	cd ${WRKSRC}/gsm; ${SETENV} ${MAKE_ENV} ${GMAKE}
	cd ${WRKSRC}/ilbc; ${SETENV} ${MAKE_ENV} ${GMAKE}
	cd ${WRKSRC}/kphone; ${SETENV} ${MAKE_ENV} ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kphone/kphone ${PREFIX}/bin
	${MKDIR} ${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/*.png ${DATADIR}/icons

.include <bsd.port.mk>
