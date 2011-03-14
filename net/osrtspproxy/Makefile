# New ports collection makefile for:	osrtspproxy
# Date created:			2002-10-13
# Whom:				Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	osrtspproxy
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://docs.real.com/docs/proxykit/
DISTNAME=	${PORTNAME}_2_0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The RTSP Proxy Kit is a reference implementation of an RTSP proxy

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

HAS_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtspproxy/rtspproxy ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/rtspproxy.sh ${PREFIX}/etc/rc.d/rtspproxy.sh.sample

.include <bsd.port.mk>
