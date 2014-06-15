# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yould
PORTVERSION=	0.3.7
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	CHEESESHOP/source/y/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pronounceable word generator

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PORTDOCS=	NEWS.txt README.txt

post-install:
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}/
	@cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
