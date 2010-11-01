# New ports collection makefile for:	synergy
# Date created:		26 March 2003
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	synergy
PORTVERSION= 	1.3.4
CATEGORIES=	sysutils
MASTER_SITES=	http://synergy-plus.googlecode.com/files/
DISTNAME=	${PORTNAME}-plus-${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Mouse and keyboard sharing utility

GNU_CONFIGURE=	yes
USE_XORG=	ice xtst x11 sm
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/configure

post-install:
	${MKDIR} ${PREFIX}/share/examples/synergy
	${INSTALL_DATA} ${WRKSRC}/examples/synergy.conf ${PREFIX}/share/examples/synergy

.include <bsd.port.mk>
