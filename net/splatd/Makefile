# Created by: Landon Fuller <landonf@opendarwin.org>
# $FreeBSD$

PORTNAME=	splatd
PORTVERSION=	1.2
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	8
CATEGORIES=	net

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Splat is the Scalable Periodic LDAP Attribute Transmogrifier

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/zconfig:devel/py-zconfig@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap>=2.3.1:net/py-ldap@${FLAVOR}
RUN_DEPENDS=	${LOCALBASE}/bin/zconfig:devel/py-zconfig@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap>=2.3.1:net/py-ldap@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	splat
USE_RC_SUBR=	splatd
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}
NO_ARCH=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	threerings

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/splat.conf ${STAGEDIR}${PREFIX}/etc/splat.conf.sample
	${MV} -f ${STAGEDIR}${PREFIX}/bin/splatd ${STAGEDIR}${PREFIX}/sbin/splatd
	${INSTALL_MAN} ${WRKSRC}/docs/man/splat.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/docs/man/splatd.8 ${STAGEDIR}${MANPREFIX}/man/man8

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/xhtml
	${INSTALL_DATA} ${WRKSRC}/docs/xhtml/* ${STAGEDIR}${DOCSDIR}/xhtml

.include <bsd.port.mk>
