# Ports collection makefile for:  pft
# Date created:			  21 July 2004
# Whom:				  Yonatan <Yonatan@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	pft
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	http://www.phenoelit.de/hp/
DISTNAME=	libPJL-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	Yonatan@xpert.com
COMMENT=	Printer Job Language library and tool

NO_WRKSUBDIR=	yes
ALL_TARGET=	libPJL.a
USE_GMAKE=	yes

post-build:
	@cd ${WRKSRC}/pft; ${GMAKE} pft

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pft/pft ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/libPJL.a ${PREFIX}/lib/

.include <bsd.port.mk>
