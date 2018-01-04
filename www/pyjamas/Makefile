# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyjamas
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	Pyjamas-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Port of Google Web Toolkit to Python

# install/require some libraries in sys.prefix
USES=		python:2.7
USE_PYTHON=	distutils autoplist pythonprefix

REINPLACE_ARGS=	-i '' -e 's,../../bin,${PREFIX}/bin,'

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/pyjamas|${DATADIR}|' ${WRKSRC}/setup.py
	${FIND} ${WRKSRC}/examples -type f -name "build.sh" -print0 | ${XARGS} -0 ${REINPLACE_CMD}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/img
	cd ${WRKSRC}/doc && ${CP} *.html ${STAGEDIR}${DOCSDIR} && \
		${CP} img/* ${STAGEDIR}${DOCSDIR}/img

.include <bsd.port.mk>
