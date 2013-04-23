# New ports collection makefile for:	rmsg
# Date created:		9 October 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	rmsg
PORTVERSION=	1.64
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.funet.fi/pub/unix/tcpip/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A network messaging system

WRKSRC=		${WRKDIR}/rmsg
MAN1=		rmsg.1
MAN8=		rmsgd.8
MAKE_JOBS_SAFE=	yes
PLIST_FILES=	bin/rmsg sbin/rmsgd
USE_RC_SUBR=	rmsgd

.include <bsd.port.mk>
