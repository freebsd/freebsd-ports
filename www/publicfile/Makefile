# New ports collection makefile for: publicfile
# Date created:		24 Jan 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	publicfile
PORTVERSION=	0.52
CATEGORIES=	www ftp
MASTER_SITES=	http://cr.yp.to/publicfile/ \
		ftp://cr.yp.to/publicfile/

MAINTAINER=	nbm@FreeBSD.org

RUN_DEPENDS=	setuidgid:${PORTSDIR}/sysutils/daemontools \
		tcpserver:${PORTSDIR}/sysutils/ucspi-tcp

ALL_TARGET=	it
INSTALL_TARGET=	setup check

post-patch:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} -s" > ${WRKSRC}/conf-ld
	@${ECHO_CMD} "${PREFIX}" > ${WRKSRC}/conf-home

.include <bsd.port.mk>
