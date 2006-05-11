# New ports collection makefile for:	tspc2
# Date created:		11 July 2005
# Whom:			pypt
#
# $FreeBSD$
#

PORTNAME=	tspc2
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.hexago.com/files/
DISTNAME=	tspc-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	shirshegsm@gmail.com
COMMENT=	TSP (Tunnel Setup Protocol) client from Freenet6

WRKSRC=		${WRKDIR}/tspc2
MAN5=		tspc.conf.5
MAN8=		tspc.8
USE_RC_SUBR=	tspc2.sh

MAKE_ARGS=	target=freebsd installdir=${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's|PREFIX|${PREFIX}|g' ${WRKSRC}/conf/tspc.conf.in
	@${REINPLACE_CMD} -e 's|PREFIX|${PREFIX}|g' ${WRKSRC}/platform/freebsd/tsp_local.c

.include <bsd.port.mk>
