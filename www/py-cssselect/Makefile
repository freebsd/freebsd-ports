# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cssselect
PORTVERSION=	0.7.1
#PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	CHEESESHOP http://docs.python.org/:sphinx
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Cssselect parses CSS3 Selectors and translates them to XPath 1.0

LICENSE=	BSD

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

# Python3 ready
USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
SPHINX_BUILD=	sphinx-build

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	 objects.inv:sphinx
BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx

REINPLACE_ARGS=	-i.bak -e 's,%%DISTDIR%%,${DISTDIR},g' \
		-e 's,%%PORTNAME%%,${PORTNAME},g'

post-patch:
	${REINPLACE_CMD} ${WRKSRC}/docs/conf.py

post-install:
	${SETENV} PYTHONPATH="${PYTHONPREFIX_SITELIBDIR}" \
	${SPHINX_BUILD} -N -a -b html ${WRKSRC}/docs ${WRKSRC}/docs.html && \
	cd ${WRKSRC}/docs.html && ${MKDIR} ${DOCSDIR} && \
	${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
