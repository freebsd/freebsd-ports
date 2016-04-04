# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xsv
PORTVERSION=	3.1
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.cogsci.ed.ac.uk/pub/XSV/
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	horia@racoviceanu.com
COMMENT=	XML Schema Validator

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ltxml>0:textproc/py-ltxml

USES=		python
USE_PYTHON=	distutils autoplist
USE_LDCONFIG=	yes

PORTDOCS=	pc-shrinkwrap xsv-status.xml xsv-status.html
PORTEXAMPLES=	triv.xml triv.xsd tiny.xml tiny.xsd
OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
