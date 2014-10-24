# Created by: Landon Fuller <landonf@opendarwin.org>
# $FreeBSD$

PORTNAME=	splatd
PORTVERSION=	1.2
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Splat is the Scalable Periodic LDAP Attribute Transmogrifier

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/bin/zconfig:${PORTSDIR}/devel/py-zconfig \
		${PYTHON_PKGNAMEPREFIX}ldap2>=2.3.1:${PORTSDIR}/net/py-ldap2
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS

USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	splat
USE_RC_SUBR=	splatd
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}
USES=		python twisted

post-install:
	${INSTALL_DATA} ${WRKSRC}/splat.conf ${STAGEDIR}${PREFIX}/etc/splat.conf.sample
	${MV} -f ${STAGEDIR}${PREFIX}/bin/splatd ${STAGEDIR}${PREFIX}/sbin/splatd
	${INSTALL_MAN} ${WRKSRC}/docs/man/splat.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/docs/man/splatd.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${MKDIR} ${STAGEDIR}${DOCSDIR}/xhtml
	${INSTALL_MAN} ${WRKSRC}/docs/xhtml/* ${STAGEDIR}${DOCSDIR}/xhtml

.include <bsd.port.mk>
