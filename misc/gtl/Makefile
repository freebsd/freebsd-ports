# New ports collection makefile for:   gtl
# Date created:        05 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtl
PORTVERSION=	0.3.3
CATEGORIES=	misc
MASTER_SITES=	http://infosun.fmi.uni-passau.de/GTL/archive/
DISTNAME=	GTL-${PORTVERSION}

MAINTAINER=	nakai@FreeBSD.org

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500035
BROKEN=		"Does not compile on 5.0"
.endif

.include <bsd.port.post.mk>
