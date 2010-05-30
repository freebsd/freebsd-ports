# New ports collection makefile for:	facile
# Date created:				2008-02-09
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	facile
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.recherche.enac.fr/log/facile/distrib/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A Functional Constraint Library

LICENSE=	LGPL
LICENSE_FILE=	${WRKSRC}/LICENSE
USE_OCAML=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	compile

post-patch:
	${REINPLACE_CMD} -e "s,make,${GMAKE},; \
		s,cp,${INSTALL_DATA}," ${WRKSRC}/Makefile

.include <bsd.port.mk>
