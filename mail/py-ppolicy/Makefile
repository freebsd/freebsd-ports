# Created by: Chifeng QU <chifeng@gmail.com>
# $FreeBSD$

PORTNAME=	ppolicy
PORTVERSION=	2.6.6
PORTREVISION=	6
CATEGORIES=	mail python
MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~vokac/activities/ppolicy/download/%SUBDIR%/ \
		http://www.chifeng.name/dist/ppolicy/%SUBDIR%/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PPolicy is tool for extending Postfix checking capabilities

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=0:dns/py-dnspython@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes
NO_BUILD=	yes
USE_RC_SUBR=	ppolicyd

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GEOIP LDAP MYSQL DOCS
OPTIONS_DEFAULT=	GEOIP LDAP

GEOIP_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/GeoIP.so:net/py-GeoIP@${FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:databases/py-MySQLdb@${FLAVOR}
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap>=2.3.1:net/py-ldap@${FLAVOR}

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
