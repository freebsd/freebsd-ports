# New ports collection makefile for:	stund
# Date created:				9 April 2004
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stund
PORTVERSION=	0.96
CATEGORIES=	net
MASTER_SITES=	SF/stun/stun/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_Aug13
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	A simple STUN (RFC 3489) server and client

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
USE_RC_SUBR=	stund
MAKE_ENV=	"CXX=${CXX}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/server ${PREFIX}/sbin/stund
	${INSTALL_PROGRAM} ${WRKSRC}/client ${PREFIX}/bin/stun_client

.include <bsd.port.mk>
