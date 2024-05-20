PORTNAME=	dkimpy-milter
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	DKIM signing and verification milter
WWW=		https://launchpad.net/dkimpy-milter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dkimpy>=1.1.0:mail/py-dkimpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}milter>=1.0.5:mail/py-milter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}authres>=1.1.0:mail/py-authres@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=0:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=1.16.0:dns/py-dnspython@${PY_FLAVOR}

USES=		python:3.9+	# Some dependencies don't support 3.8
USE_PYTHON=	autoplist concurrent distutils
USE_RC_SUBR=	dkimpy-milter
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

USERS=		dkimpy-milter
GROUPS=		dkimpy-milter

PYDISTUTILS_CONFIGUREARGS=	expand --rundir=/var/run

NO_ARCH=	yes

PLIST_FILES=	'@dir(${USERS},${GROUPS},755) /var/run/dkimpy-milter' \
		'@sample etc/dkimpy-milter/dkimpy-milter.conf.sample'

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/dkimpy-milter \
	      ${STAGEDIR}${PREFIX}/etc/dkimpy-milter
	${INSTALL_DATA} ${WRKSRC}/etc/dkimpy-milter.conf \
	      ${STAGEDIR}${PREFIX}/etc/dkimpy-milter/dkimpy-milter.conf.sample

.include <bsd.port.mk>
