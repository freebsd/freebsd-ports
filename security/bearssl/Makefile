# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bearssl
PORTVERSION=	0.2
PORTREVISION=	0
CATEGORIES=	security devel
MASTER_SITES=	https://bearssl.org/

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Implementation of TLS/SSL in C

LICENSE=	MIT

USES=		compiler:c11

post-patch:
	${REINPLACE_CMD} 's|CC = gcc|CC ?= gcc|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/brssl ${STAGEDIR}${LOCALBASE}/bin/
	(cd ${WRKSRC}/inc && ${COPYTREE_SHARE} . ${STAGEDIR}${LOCALBASE}/include/)
	${INSTALL_DATA} ${WRKSRC}/libbearssl.a ${STAGEDIR}${LOCALBASE}/lib/

.include <bsd.port.mk>
