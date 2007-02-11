# New ports collection makefile for:	xperfmon++
# Date created:		23. Oct 1998
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	xperfmon++
PORTVERSION=	3.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/
DISTNAME=	xperfmon++
EXTRACT_SUFX=	v1.1.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xperfmon++ : A graphical X11 system performance monitor

DEPRECATED=	Broken on all supported versions of FreeBSD
EXPIRATION_DATE=2007-03-10

LATEST_LINK=	xperfmon3

USE_IMAKE=	yes
MAN1=		xperfmon++.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile in NFS related statistics"
.endif

.include <bsd.port.post.mk>
