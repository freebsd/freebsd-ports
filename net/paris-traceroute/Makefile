# New ports collection makefile for:  paris-traceroute
# Date created:		10 January 2007
# Whom:			dikshie@sfc.wide.ad.jp
#
# $FreeBSD$
#

PORTNAME=	paris-traceroute
PORTVERSION=	0.92
CATEGORIES=	net
MASTER_SITES=	http://paris-traceroute.net/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}-dev

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Paris traceroute is network diagnosis and measurement tools

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/paris-traceroute

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
