# New ports collection makefile for:	vcdgear
# Date created:	 	06 January 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vcdgear
PORTVERSION=	1.5
CATEGORIES= 	graphics
MASTER_SITES=	http://www.vcdgear.org/files/

MAINTAINER=	cpiazza@FreeBSD.org

USE_ZIP=	yes
.include <bsd.port.pre.mk>
.if ${OSVERSION} < 300004
BROKEN=	'Only an ELF binary is distributed'
.endif

.if ${ARCH} == i386
DISTNAME=	${PORTNAME}15_FreeBSD4.0_Intel
.else if ${ARCH} == alpha
DISTNAME=	${PORTNAME}15_FreeBSD4.0_Alpha
.endif

NO_BUILD=	true
NO_WRKSUBDIR=	true

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vcdgear15_static ${PREFIX}/bin/vcdgear

.include <bsd.port.post.mk>
