# Created by: Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
# $FreeBSD$

PORTNAME=	osrtspproxy
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/rtsp/RTSP%20Proxy%20Kit/${PORTVERSION}
DISTNAME=	${PORTNAME}_2_0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The RTSP Proxy Kit - A reference implementation of an RTSP proxy

HAS_CONFIGURE=	YES

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtspproxy/rtspproxy ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/rtspproxy.sh ${PREFIX}/etc/rc.d/rtspproxy.sh.sample

.include <bsd.port.mk>
