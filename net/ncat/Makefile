# New ports collection Makefile for:	ncat
# Date created:		22 August 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	ncat
PORTVERSION=	1.2.0
CATEGORIES=	net
DISTNAME=	canonware-1.2.0
MASTER_SITES=	http://www.canonware.com/download/canonware/

MAINTAINER=	jasone@FreeBSD.org

BUILD_DEPENDS=	cook:${PORTSDIR}/devel/cook

GNU_CONFIGURE=	yes

MAN1=		ncat.1
MANCOMPRESSED=	no

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook bin/ncat/src/ncat)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook ncat_install_a)

post-install:
	@strip ${PREFIX}/bin/ncat

.include <bsd.port.mk>
