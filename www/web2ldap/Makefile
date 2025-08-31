PORTNAME=	web2ldap
PORTVERSION=	1.8.1
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	PYPI https://www.web2ldap.de/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Python-based WWW gateway to LDAP servers
WWW=		https://web2ldap.de/

LICENSE=	APACHE20

RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}asn1crypto>=0.22.0:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=2.0.0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlwt>0:textproc/py-xlwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap0>=1.4.7:net/py-ldap0@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iso3166>=1.0.1:textproc/py-iso3166@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.7.1:net-mgmt/py-prometheus-client@${PY_FLAVOR} \
		${LOCALBASE}/etc/mime.types:misc/mime-support

OPTIONS_DEFINE=	DOCS
USES=		cpe python
USE_PYTHON=	distutils autoplist

SUB_FILES=	pkg-message ${PORTNAME}
USE_RC_SUBR=	${PORTNAME}
NO_ARCH=	yes

.include <bsd.port.mk>
