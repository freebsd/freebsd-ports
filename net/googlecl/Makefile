# New ports collection makefile for:	googlecl
# Date created:		2010-06-19
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	googlecl
PORTVERSION=	0.9.13
CATEGORIES=	net www python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Command line tools for the Google Data APIs

LICENSE=	AL2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gdata/__init__.py:${PORTSDIR}/devel/py-gdata

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		google.1
.endif

PORTDOCS=	*

post-install:
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/man/${MAN1} ${MANPREFIX}/man/man1
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
