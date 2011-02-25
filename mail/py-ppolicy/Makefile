# New ports collection makefile for:	py-ppolicy
# Date created:				27 November 2008
# Whom:	      				Chifeng QU <chifeng@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ppolicy
PORTVERSION=	2.6.6
PORTREVISION=	2
CATEGORIES=	mail python
MASTER_SITES=	http://kmlinux.fjfi.cvut.cz/~vokac/activities/ppolicy/download/%SUBDIR%/ \
		http://www.chifeng.name/dist/ppolicy/%SUBDIR%/

MAINTAINER?=	chifeng@gmail.com
COMMENT=	PPolicy is tool for extending Postfix checking capabilities

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dns/__init__.py:${PORTSDIR}/dns/py-dnspython

USE_PYTHON=	2.4+
USE_PYDISTUTILS=yes
USE_TWISTED=	yes
NO_BUILD=	yes
USE_RC_SUBR=	ppolicyd.sh
DOCSDIR?=	${PREFIX}/share/doc/py-${PORTNAME}

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}
SUB_FILES=	pkg-message

OPTIONS=	GeoIP "Use GeoIP support" On \
		LDAP "Use LDAP support" On \
		MYSQL "Use MySQL support" Off

.include <bsd.port.pre.mk>

.if defined(WITH_GeoIP)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/GeoIP.so:${PORTSDIR}/net/py-GeoIP
.endif
.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:${PORTSDIR}/databases/py-MySQLdb
.endif
.if defined(WITH_LDAP)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ldap2>=2.3.1:${PORTSDIR}/net/py-ldap2
.endif

post-install:
.if !defined(NOPORTDOCS)
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

.include <bsd.port.post.mk>
