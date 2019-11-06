# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	TracGantt
PORTVERSION=	0.3.2a
PORTREVISION=	8
CATEGORIES=	www devel python
MASTER_SITES=	http://willbarton.com/files/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMEPREFIX=	trac-

MAINTAINER=	dryice@dryice.name
COMMENT=	Plugin to creates Gantt charts for trac

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	trac>=0.11:www/trac

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

PORTDOCS=	PKG-INFO README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
