# New ports collection makefile for:    dtv
# Date created:         10 Feb 2002
# Whom:                 dillon
#
# $FreeBSD$
#

PORTNAME=	dtv
PORTVERSION=	0.50
CATEGORIES=	multimedia
MASTER_SITES=	http://apollo.backplane.com/FreeBSDPorts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A client/server based TV capture/display program

USE_XLIB=	yes
RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

ONLY_FOR_ARCHS=	alpha i386 ia64

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
IGNORE=		"cannot be build on alpha 4.x, which does not have bktr hardware support"
.endif

.include <bsd.port.post.mk>
