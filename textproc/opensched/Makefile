# New ports collection makefile for:	opensched
# Date created:				31 January 2001
# Whom:					Daniel McRobb <dwm@caimis.com>
#
# $FreeBSD$
#

PORTNAME=	opensched
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.m-tech.ab.ca/download/sched/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A project scheduler

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_GMAKE=	yes

MAN1=		opensched.1
PLIST_FILES=	bin/opensched

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
