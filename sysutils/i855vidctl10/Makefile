# New ports collection makefile for:	i855vidctl
# Date created:				27 August 2004
# Whom:					Oliver Bantke
#
# $FreeBSD$
#

PORTNAME=	i855vidctl
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.t-g-p.org/
DISTNAME=	${PORTNAME}10

MAINTAINER=	oliver.bantke@t-g-p.org
COMMENT=	Resolution tool for Centrino based laptops

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

.include <bsd.port.post.mk>
