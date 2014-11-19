# $FreeBSD$

PORTNAME=	automx
PORTVERSION=	0.10.2
CATEGORIES=	mail

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Handles mail account profile requests from mail clients

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}ipaddr>=0:${PORTSDIR}/devel/py-ipaddr \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}m2crypto>=0:${PORTSDIR}/security/py-m2crypto \
		wget:${PORTSDIR}/ftp/wget \
		dig:${PORTSDIR}/dns/bind-tools

GH_ACCOUNT=	sys4
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	2eb1c64

USES=		python
USE_GITHUB=	yes
NO_BUILD=	yes
PORTDATA=	*
PORTDOCS=	*

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	MEMCACHE
MEMCACHE_DESC=	Add memcache support
MEMCACHE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}memcached>=0:${PORTSDIR}/databases/py-memcached

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/src && \
	    ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR})
	${INSTALL_DATA} ${WRKSRC}/src/automx_wsgi.py ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/automx-test ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/conf/automx.conf \
		${STAGEDIR}${PREFIX}/etc/automx.conf.sample
.for s in 1 5
	${INSTALL_MAN} ${WRKSRC}/doc/man/man$s/* ${STAGEDIR}${PREFIX}/man/man$s/
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "[^m]*" ${STAGEDIR}${DOCSDIR})
	${INSTALL_MAN} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/BASIC_CONFIGURATION_README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
