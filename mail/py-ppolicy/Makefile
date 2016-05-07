# Created by: Chifeng QU <chifeng@gmail.com>
# $FreeBSD$

PORTNAME=	ppolicy
PORTVERSION=	2.6.6
PORTREVISION=	5
CATEGORIES=	mail python
MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~vokac/activities/ppolicy/download/%SUBDIR%/ \
		http://www.chifeng.name/dist/ppolicy/%SUBDIR%/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PPolicy is tool for extending Postfix checking capabilities

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dns/__init__.py:dns/py-dnspython

USES=		python twisted
USE_PYTHON=	distutils autoplist
NO_BUILD=	yes
NO_ARCH=	yes
USE_RC_SUBR=	ppolicyd

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GEOIP LDAP MYSQL DOCS
OPTIONS_DEFAULT=	GEOIP LDAP

GEOIP_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/GeoIP.so:net/py-GeoIP
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:databases/py-MySQLdb
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap>=2.3.1:net/py-ldap

post-install:
	${INSTALL_DATA} ${WRKSRC}/ppolicy.conf ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/ppolicy.tap ${STAGEDIR}${PREFIX}/sbin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MODULES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TESTS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ppolicy.sql ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
