# New ports collection makefile for:	pyjamas
# Date created:		2008-10-07
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyjamas
PORTVERSION=	0.4
#PORTREVISION=	0
CATEGORIES=	www python
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A port of Google Web Toolkit to Python

USE_PYTHON=	yes

RM_OPTS=	-R

REINPLACE_ARGS=	-i '' -e 's,../../builder,${DATADIR}/builder,'

post-patch:
	${FIND} ${WRKSRC}/examples -type f -name "build.sh" -print0 | ${XARGS} -0 ${REINPLACE_CMD}

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py addons builder library pyjs stubs

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${DATADIR}

.if !defined(NOPORTDOCS)
	${MV} ${DATADIR}/doc ${DOCSDIR}
.else
	${RM} ${RM_OPTS} ${DATADIR}/doc
.endif

post-install:
	${CHMOD} a+x ${DATADIR}/builder/build.py ${DATADIR}/pyjs/pyjs.py
.if !defined(NOPORTEXAMPLES)
	${MV} ${DATADIR}/examples ${EXAMPLESDIR}
	${FIND} ${EXAMPLESDIR} -type f -name "*.sh" -print0 | ${XARGS} -0 ${CHMOD} a+x
.else
	${RM} ${RM_OPTS} ${DATADIR}/examples
.endif

.include <bsd.port.mk>
