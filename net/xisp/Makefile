# New ports collection makefile for:	xisp
# Date created:		June 24, 1999
# Whom:			tm@onepost.net
#
# $FreeBSD$
#

PORTNAME=	xisp
PORTVERSION=	2.7
CATEGORIES=	net
MASTER_SITES=	http://xisp.hellug.gr/release/

PATCH_SITES=	http://www.ml-search.com/xisp/distfiles/
PATCHFILES=	xisp-2.7-freebsd-patch-20030126.gz

MAINTAINER=	tm@onepost.net
COMMENT=	A user-friendly X interface to pppd/chat

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms

USE_XPM=	yes

MAN1=		xisp.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile due to deprecation of varargs.h"
.endif

.include <bsd.port.post.mk>
