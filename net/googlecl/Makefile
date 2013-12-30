# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googlecl
PORTVERSION=	0.9.14
CATEGORIES=	net www python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Command line tools for the Google Data APIs

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gdata/__init__.py:${PORTSDIR}/devel/py-gdata

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		google.1
.endif

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/man/${MAN1} ${MANPREFIX}/man/man1
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
