# Ports collection makefile for:  dcetest
# Date created:			  Jan 11 2003
# Whom:				  Yonatan <Yonatan@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	dcetest
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	http://www.atstake.com/research/tools/info_gathering/
DISTNAME=	dcetest
EXTRACT_SUFX=	.tar

MAINTAINER=	Yonatan@xpert.com
COMMENT=	Utility to dump MSRPC endpoint information from Windows systems

ALL_TARGET=	dcetest

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dcetest ${PREFIX}/bin

.if !target(post-install) && (${PORTNAME} == "dcetest")
post-install:
	@strip ${PREFIX}/bin/dcetest
.endif

.include <bsd.port.mk>
