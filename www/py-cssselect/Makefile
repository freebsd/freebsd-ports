# New ports collection makefile for:	cssselect
# Date created:		2012-05-02
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cssselect
PORTVERSION=	0.7.1
#PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Cssselect parses CSS3 Selectors and translates them to XPath 1.0

LICENSE=	BSD

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=	DOCS

.include <bsd.port.options.mk>

# Python3 ready
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
SPHINX_BUILD=	sphinx-build

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx

post-install:
	${SETENV} PYTHONPATH="${PYTHONPREFIX_SITELIBDIR}" \
	${SPHINX_BUILD} -a -b html ${WRKSRC}/docs ${WRKSRC}/docs.html && \
	cd ${WRKSRC}/docs.html && ${MKDIR} ${DOCSDIR} && \
	${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
