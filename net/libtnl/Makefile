# New ports collection makefile for:    libtnl
# Date created:         26 Jan 2006
# Whom:                 aaron@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libtnl
PORTVERSION=	1.5.0
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	opentnl
DISTNAME=	tnl-${PORTVERSION}-source

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	A robust, secure, easy to use cross-platform C++ networking API

WRKSRC=		${WRKDIR}/tnl/tnl
INSTALLS_SHLIB=	yes
ONLY_FOR_ARCHS=	i386

post-extract:
	@${CP} ${PATCHDIR}/Makefile.bsd ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${PREFIX}/include/tnl

.include <bsd.port.mk>
