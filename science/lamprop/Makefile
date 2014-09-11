# Created by: rsmith@xs4all.nl
# $FreeBSD$

PORTNAME=	lamprop
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://rsmith.home.xs4all.nl/files/

MAINTAINER=	rsmith@xs4all.nl
COMMENT=	Calculates properties of fiber reinforced composites

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYNUMPY}

USES=		zip python:2.7

do-install:
	cd ${WRKSRC} && ${MAKE} PREFIX=${STAGEDIR}${PREFIX} install

.include <bsd.port.mk>
