PORTNAME=	automx
PORTVERSION=	0.10.2
DISTVERSIONPREFIX=	v
PORTREVISION=	7
CATEGORIES=	mail

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Handles mail account profile requests from mail clients
WWW=		http://www.automx.org/en/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>=0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipaddr>=0:devel/py-ipaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}m2crypto>=0:security/py-m2crypto@${PY_FLAVOR} \
		wget:ftp/wget \
		dig:dns/bind-tools

GH_ACCOUNT=	sys4

USES=		python
USE_GITHUB=	yes
NO_BUILD=	yes
NO_ARCH=	yes
PORTDATA=	*
PORTDOCS=	*

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS MEMCACHE
MEMCACHE_DESC=	Add memcache support
MEMCACHE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-memcached>=0:databases/py-python-memcached@${PY_FLAVOR}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/src && \
	    ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR})
	${INSTALL_DATA} ${WRKSRC}/src/automx_wsgi.py ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/automx-test ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/conf/automx.conf \
		${STAGEDIR}${PREFIX}/etc/automx.conf.sample
.for s in 1 5
	${INSTALL_MAN} ${WRKSRC}/doc/man/man$s/* ${STAGEDIR}${PREFIX}/share/man/man$s/
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "[^m]*" ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/BASIC_CONFIGURATION_README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
