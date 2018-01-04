# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=	HTMLgen
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	LOCAL/dryice \
		http://dryice.name/computer/FreeBSD/distfiles/ \
		http://starship.python.net/crew/friedrich/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	HTMLgen

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python library for the generation of HTML documents

USES=		python:2 shebangfix
USE_PYTHON=	flavors
NO_BUILD=	yes
NO_ARCH=	yes
SHEBANG_FILES=	HTMLutil.py barchart.py

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|python |${PYTHON_CMD} |' ${WRKSRC}/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "README html image" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
