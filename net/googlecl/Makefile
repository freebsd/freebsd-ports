# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googlecl
PORTVERSION=	0.9.14
CATEGORIES=	net www python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Command line tools for the Google Data APIs

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdata>0:${PORTSDIR}/devel/py-gdata

USES=		python
USE_PYTHON=	distutils

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.* ${STAGEDIR}${DOCSDIR}
.endif
	${INSTALL_MAN} ${WRKSRC}/man/google.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
