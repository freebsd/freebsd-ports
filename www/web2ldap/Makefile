PORTNAME=	web2ldap
PORTVERSION=	1.8.1
PORTREVISION=	6
CATEGORIES=	www python
MASTER_SITES=	PYPI \
		https://www.web2ldap.de/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Python-based WWW gateway to LDAP servers
WWW=		https://web2ldap.de/

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:misc/mime-support \
		${PYTHON_PKGNAMEPREFIX}asn1crypto>=0.22.0:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=2.0.0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iso3166>=1.0.1:textproc/py-iso3166@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap0>=1.4.7:net/py-ldap0@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.7.1:net-mgmt/py-prometheus-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlwt>0:textproc/py-xlwt@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist pep517

USE_RC_SUBR=	${PORTNAME}
NO_ARCH=	yes
SUB_FILES=	${PORTNAME} pkg-message
OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

# cgi and imghdr were removed in Python 3.13 (crypt and sndhdr are made
# optional in files/)
.if ${PYTHON_REL} >= 31300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}legacy-cgi>=0:www/py-legacy-cgi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}standard-imghdr>=0:devel/py-standard-imghdr@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
