# Created by: Chifeng QU <chifeng@gmail.com>
# $FreeBSD$

PORTNAME=	ppolicy
PORTVERSION=	2.6.6
PORTREVISION=	3
CATEGORIES=	mail python
MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~vokac/activities/ppolicy/download/%SUBDIR%/ \
		http://www.chifeng.name/dist/ppolicy/%SUBDIR%/

MAINTAINER?=	chifeng@gmail.com
COMMENT=	PPolicy is tool for extending Postfix checking capabilities

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dns/__init__.py:${PORTSDIR}/dns/py-dnspython

USES=		twisted
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
NO_BUILD=	yes
USE_RC_SUBR=	ppolicyd
DOCSDIR?=	${PREFIX}/share/doc/py-${PORTNAME}

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GEOIP LDAP MYSQL DOCS
OPTIONS_DEFAULT=	GEOIP LDAP

NO_STAGE=	yes
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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MODULES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TESTS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ppolicy.sql ${DOCSDIR}
.endif
	${INSTALL_DATA} -m 0644 ${WRKSRC}/ppolicy.conf ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/ppolicy.tap ${PREFIX}/sbin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
