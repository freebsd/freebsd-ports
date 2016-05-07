# Created by: Landon Fuller <landonf@opendarwin.org>
# $FreeBSD$

PORTNAME=	splatd
PORTVERSION=	1.2
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Splat is the Scalable Periodic LDAP Attribute Transmogrifier

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/zconfig:devel/py-zconfig \
		${PYTHON_PKGNAMEPREFIX}ldap>=2.3.1:net/py-ldap
RUN_DEPENDS=	${LOCALBASE}/bin/zconfig:devel/py-zconfig \
		${PYTHON_PKGNAMEPREFIX}ldap>=2.3.1:net/py-ldap

USES=		python twisted
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	splat
USE_RC_SUBR=	splatd
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}
NO_ARCH=	yes

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
