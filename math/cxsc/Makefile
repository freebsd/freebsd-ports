# ex:ts=8
# New ports collection makefile for:	cxsc
# Date created:			Aug 11, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cxsc
PORTVERSION=	2.0b
PORTREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	http://www.math.uni-wuppertal.de/wrswt/xsc/cxsc/
DISTNAME=	${PORTNAME}-2-0-beta

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class library for eXtended Scientific Computing

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile with gcc 3.4.2"
.endif

.include <bsd.port.post.mk>
