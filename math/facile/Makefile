# Created by: arved
# $FreeBSD$

PORTNAME=	facile
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.recherche.enac.fr/log/facile/distrib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Functional Constraint Library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE
USE_OCAML=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	compile

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e "s,make,${GMAKE},; \
		s,cp,${INSTALL_DATA}," ${WRKSRC}/Makefile

.include <bsd.port.mk>
