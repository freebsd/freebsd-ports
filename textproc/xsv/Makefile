# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xsv
PORTVERSION=	3.1
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.cogsci.ed.ac.uk/pub/XSV/
DISTNAME=	${PORTNAME:U}-${DISTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	XML Schema Validator

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ltxml>0:${PORTSDIR}/textproc/py-ltxml

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=  yes
INSTALLS_EGGINFO=	yes
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
