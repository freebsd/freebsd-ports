# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yould
PORTVERSION=	0.3.7
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	CHEESESHOP/source/y/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pronounceable word generator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

PORTDOCS=	NEWS.txt README.txt

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
