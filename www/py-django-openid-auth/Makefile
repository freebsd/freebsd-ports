# Created by: Matthew X. Economou <xenophon+fbsdports@irtnog.org>
# $FreeBSD$

PORTNAME=	django-openid-auth
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	www security python
MASTER_SITES=	http://launchpadlibrarian.net/80020365/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	xenophon+fbsdports@irtnog.org
COMMENT=	OpenID integration for django.contrib.auth

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>=1.3.1:www/py-django18@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-openid>=2.2.5:security/py-python-openid@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils

NO_WRKSUBDIR=	yes

PORTDOCS=	*.txt *.html
PORTEXAMPLES=	example_consumer
OPTIONS_DEFINE= DOCS EXAMPLES

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.txt	${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/TODO.txt	${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/openid.html	${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/openid.txt	${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/example_consumer
	${INSTALL_MAN} ${WRKSRC}/example_consumer/* ${STAGEDIR}${EXAMPLESDIR}/example_consumer
.endif

.include <bsd.port.mk>
