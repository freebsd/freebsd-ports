# New ports collection makefile for:	stund
# Date created:				9 April 2004
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stund
PORTVERSION=	0.91
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	stun
DISTNAME=	${PORTNAME}_${PORTVERSION}_Feb21
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	A simple STUN (RFC 3489) server and client

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/server ${LOCALBASE}/sbin/stund
	${INSTALL_PROGRAM} ${WRKSRC}/client ${LOCALBASE}/bin/stun_client

.include <bsd.port.mk>
