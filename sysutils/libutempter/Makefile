# New ports collection makefile for:    libutempter
# Date created:				 18 Aug 2004 14:50:41 CEST
# Whom:					Michael Nottebrock <lofi@freebsd.org>,
#					David Malone <dwmalone@maths.tcd.ie>
# $FreeBSD$

PORTNAME=	libutempter
PORTVERSION=	1.1.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.altlinux.org/pub/people/ldv/utempter/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interface to record user sessions to utmp and wtmp files

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900004
IGNORE=		is now contained in the base system
.endif

.include <bsd.port.post.mk>
