# New ports collection makefile for:	ucspi-unix
# Date created:         23.Sep.2003
# Whom:                 patrick@rinke-bochum.de
#
# $FreeBSD$
#

PORTNAME=	ucspi-unix
PORTVERSION=	0.36
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://untroubled.org/ucspi-unix/

MAINTAINER=	patrick@rinke-bochum.de
COMMENT=	UNIX-domain socket client-server command-line tools

BUILD_DEPENDS=	${LOCALBASE}/include/bglibs/sysdeps.h:${PORTSDIR}/devel/bglibs


MAN1=	unixclient.1 unixserver.1

post-patch:
	${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-home
	${ECHO_CMD} ${CC} ${CFLAGS} -I${LOCALBASE}/include/bglibs > ${WRKSRC}/conf-cc
	${ECHO_CMD} ${CC} ${LDFLAGS} -s -L${LOCALBASE}/lib > ${WRKSRC}/conf-ld
	${ECHO_CMD} ${PREFIX}/man > ${WRKSRC}/conf-man
	

do-install:
	cd ${WRKSRC} && ./installer

.include <bsd.port.mk>
