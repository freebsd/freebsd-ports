# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmltv
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-xmltv-${PORTVERSION}

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	Python module that provides access to XMLTV TV listings

LICENSE=	LGPL21

BROKEN=		Unfetchable (google code has gone away)

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	python-xmltv
PROJECTHOST=	python-xmltv
OPTIONS_DEFINE= DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README.txt
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
