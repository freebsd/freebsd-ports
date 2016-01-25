# $FreeBSD$

PORTNAME=	pyldap
PORTVERSION=	2.4.21
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Fork of python-ldap with Python 3 support

LICENSE=	PSFL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0:${PORTSDIR}/devel/py-pyasn1-modules

CONFLICTS_INSTALL=	py27-ldap
USES=		python
USE_PYTHON=	autoplist distutils
USE_OPENLDAP=		yes
WANT_OPENLDAP_VER=	24

REPLACE_ARGS=	-e 's,/usr/include/sasl,${LOCALBASE}/include/sasl,' \
		-e 's,/usr/local,${LOCALBASE},'

OPTIONS_DEFINE=	SASL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSASL}
WANT_OPENLDAP_SASL=	yes
CONFLICTS+=		openldap24-client-2.*
.endif

do-configure:
	@${REINPLACE_CMD} ${REPLACE_ARGS} ${WRKSRC}/setup.cfg
.if ! ${PORT_OPTIONS:MSASL}
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py -q setopt -c _ldap -s HAVE_TLS -o defines
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py -q saveopts
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_ldap.so

.include <bsd.port.mk>
