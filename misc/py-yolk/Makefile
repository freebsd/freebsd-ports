# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yolk
PORTVERSION=	0.4.3
PORTREVISION=	0
CATEGORIES=	misc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Command-line tool for querying PyPI and Python packages installed

LICENSE=	BSD3CLAUSE

USES=		python:2
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}.1
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/{} ";"
	cd ${WRKSRC}/examples && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR}/{} ";"
.endif

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} == 2701 || ${PYTHON_REL} == 3200
IGNORE=	does not work with ${PYTHON_VERSION} (see http://goo.gl/SZpDN)
.endif

.include <bsd.port.post.mk>
