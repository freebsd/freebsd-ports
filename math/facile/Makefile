# Created by: arved
# $FreeBSD$

PORTNAME=	facile
PORTVERSION=	1.1.3
CATEGORIES=	math
MASTER_SITES=	http://opti.recherche.enac.fr/facile/distrib/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Functional Constraint Library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_OCAML=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=	compile

post-configure:
	${REINPLACE_CMD} -e "s,make,${MAKE_CMD},; \
		s,cp,${INSTALL_DATA},;\
		s,mkdir,${MKDIR}," ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s,${LOCALBASE},${STAGEDIR}${PREFIX}," \
		${WRKSRC}/config_Makefile

.include <bsd.port.mk>
