# Ports collection makefile for:  muuz
# Date created:			  21 March 2000
# Whom:				  kline@thought.org
#
# $FreeBSD$
#

PORTNAME=	muuz
PORTVERSION=	0.27.2
CATEGORIES=	misc
MASTER_SITES=	http://muuz.deadbbs.com/FreeBSD/muuz/

MAINTAINER=	kline@thought.org
COMMENT=	X11 and sound tool that promotes relaxation, meditation, fun, more

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d

USE_IMAKE=	yes
MAN1=		muuz.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
