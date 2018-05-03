# Created by: Oddbjorn Steffensen <oddbjorn@tricknology.org>
# $FreeBSD$

PORTNAME=	web2ldap
PORTVERSION=	1.3.16
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Python-based WWW gateway to LDAP servers

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asn1crypto>=0.22.0:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dns>=0:dns/py-dns@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlwt>0:textproc/py-xlwt@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap0>=0.0.60:net/py-ldap0@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/pyweblib/__init__.py:www/py-pyweblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipaddr>0:devel/py-ipaddr@${PY_FLAVOR} \
		${LOCALBASE}/etc/mime.types:misc/mime-support

OPTIONS_DEFINE=	DOCS
USES=		cpe python:2.7
USE_PYTHON=	distutils autoplist

SUB_FILES=	pkg-message ${PORTNAME}
USE_RC_SUBR=	${PORTNAME}
NO_ARCH=	yes
PLIST_DIRS=	${DATADIR} ${DATADIR}/var ${DATADIR}/var/log ${DATADIR}/var/run /var/log/web2ldap

post-build:
		${TOUCH} ${WRKSRC}/etc/web2ldap/ssl/.placeholder

post-stage:
		${MKDIR} ${STAGEDIR}${DATADIR}/var/log
		${MKDIR} ${STAGEDIR}${DATADIR}/var/run
		${MKDIR} ${STAGEDIR}/var/log/web2ldap

.include <bsd.port.mk>
