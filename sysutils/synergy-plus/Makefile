# New ports collection makefile for:	synergy-plus
# Date created:		2009-10-11
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	synergy-plus
PORTVERSION=	1.3.4
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Maintenance fork for implementing bug fixes to the original Synergy

CONFLICTS=	synergy-1*

GNU_CONFIGURE=	yes
USE_XORG=	ice xtst x11 sm
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/configure

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/synergy.conf ${EXAMPLESDIR}

.include <bsd.port.mk>
