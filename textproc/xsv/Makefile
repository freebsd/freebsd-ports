# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xsv
PORTVERSION=	3.1
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.cogsci.ed.ac.uk/pub/XSV/
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML Schema Validator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ltxml>0:textproc/py-ltxml

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

PORTDOCS=	pc-shrinkwrap xsv-status.xml xsv-status.html
PORTEXAMPLES=	triv.xml triv.xsd tiny.xml tiny.xsd

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
