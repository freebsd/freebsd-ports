# $FreeBSD$

PORTNAME=	ldap
PORTVERSION=	2.4.44
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	LDAP module for python, for OpenLDAP2

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>0:devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>0:devel/py-pyasn1-modules

CONFLICTS_INSTALL=	py27-pyldap
USES=		python:-2.7
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
