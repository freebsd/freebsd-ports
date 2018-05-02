# $FreeBSD$

PORTNAME=	pyldap
PORTVERSION=	2.4.45
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Fork of python-ldap with Python 3 support

DEPRECATED=	This code has merged back to python-ldap. Please use net/py-ldap instead
EXPIRATION_DATE=	2018-06-02

LICENSE=	PSFL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0:devel/py-pyasn1-modules@${FLAVOR}

CONFLICTS_INSTALL=	py27-ldap
USES=		python
USE_PYTHON=	autoplist distutils
USE_OPENLDAP=	yes
WANT_OPENLDAP_VER=	24

OPTIONS_DEFINE=	SASL

SASL_VARS=	WANT_OPENLDAP_SASL=yes
SASL_CONFLICTS=	openldap24-client-2.*

do-configure:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},' ${WRKSRC}/setup.cfg

do-configure-SASL-off:
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py -q setopt -c _ldap -s HAVE_TLS -o defines
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py -q saveopts

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_ldap.so

.include <bsd.port.mk>
