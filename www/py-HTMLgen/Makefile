# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=	HTMLgen
PORTVERSION=	2.2.2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/ \
		http://starship.python.net/crew/friedrich/
MASTER_SITE_SUBDIR=	dryice
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	HTMLgen

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python library for the generation of HTML documents

USES=		python:2
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|python |${PYTHON_CMD} |' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "README html image" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
