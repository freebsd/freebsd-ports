PORTNAME=	uwsgitop
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	PYPI

MAINTAINER=	demon@FreeBSD.org
COMMENT=	uWSGI top-like app
WWW=		https://pypi.org/project/uwsgitop/

USES=		python
USE_PYTHON=	distutils concurrent optsuffix

PLIST_FILES=	bin/uwsgitop %%DOCSDIR%%/README.rst

post-install:
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
