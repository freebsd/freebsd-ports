PORTNAME=	pyweblib
DISTVERSION=	1.3.13
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Yet another web programming framework for Python
WWW=		http://www.stroeder.com/pylib/PyWebLib/

LICENSE=	GPLv2

DEPRECATED=	Python 2 only (implicit relative imports); fails to import on Python 3
EXPIRATION_DATE=	2026-12-17

USES=		python
USE_PYTHON=	autoplist distutils

PORTDOCS=	pyweblib.forms.html pyweblib.helper.html \
		pyweblib.html pyweblib.httphelper.html \
		pyweblib.session.html pyweblib.sslenv.html
EXAMPLES=	*.py

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/cgi-bin ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/cgi-bin
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/htdocs/pydoc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
