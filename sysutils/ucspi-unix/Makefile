# New ports collection makefile for:	ucspi-unix
# Date created:         23.Sep.2003
# Whom:                 patrick@rinke-bochum.de
#
# $FreeBSD$
#

PORTNAME=	ucspi-unix
PORTVERSION=	0.36
CATEGORIES=	sysutils
MASTER_SITES=	http://untroubled.org/ucspi-unix/

MAINTAINER=	patrick@rinke-bochum.de
COMMENT=	UNIX-domain socket client-server command-line tools

BUILD_DEPENDS=	bglibs.1:${PORTSDIR}/devel/bglibs

USE_REINPLACE=yes

pre-build:
	${ECHO_CMD} ${PREFIX}		> ${WRKSRC}/conf-home
	${ECHO_CMD} ${CC} ${CFLAGS}	> ${WRKSRC}/conf-cc

do-install:
	cd ${WRKSRC} && ./installer

.include <bsd.port.mk>
