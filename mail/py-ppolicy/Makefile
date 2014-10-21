# Created by: Chifeng QU <chifeng@gmail.com>
# $FreeBSD$

PORTNAME=	ppolicy
PORTVERSION=	2.6.6
PORTREVISION=	4
CATEGORIES=	mail python
MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~vokac/activities/ppolicy/download/%SUBDIR%/ \
		http://www.chifeng.name/dist/ppolicy/%SUBDIR%/

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	PPolicy is tool for extending Postfix checking capabilities

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dns/__init__.py:${PORTSDIR}/dns/py-dnspython

USES=		python twisted
USE_PYTHON=	distutils autoplist
NO_BUILD=	yes
USE_RC_SUBR=	ppolicyd
DOCSDIR?=	${PREFIX}/share/doc/py-${PORTNAME}

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GEOIP LDAP MYSQL DOCS
OPTIONS_DEFAULT=	GEOIP LDAP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGEOIP}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/GeoIP.so:${PORTSDIR}/net/py-GeoIP
.endif
.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:${PORTSDIR}/databases/py-MySQLdb
.endif
.if ${PORT_OPTIONS:MLDAP}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ldap2>=2.3.1:${PORTSDIR}/net/py-ldap2
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MODULES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TESTS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ppolicy.sql ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ppolicy.conf ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/ppolicy.tap ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
