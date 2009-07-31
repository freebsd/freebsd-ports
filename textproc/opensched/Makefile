# New ports collection makefile for:	opensched
# Date created:				31 January 2001
# Whom:					Daniel McRobb <dwm@caimis.com>
#
# $FreeBSD$
#

PORTNAME=	opensched
PORTVERSION=	0.1.0
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://mtechit.com/dlsoftware/opensched/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A project scheduler

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_GMAKE=	yes

MAN1=		opensched.1
PLIST_FILES=	bin/opensched

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "i386"
BROKEN=		Does not install
.endif
.endif

.if ${ARCH} == "alpha"
BROKEN=		Does not compile
.endif

.include <bsd.port.post.mk>
