# $FreeBSD$

PORTNAME=	cloud-init
PORTVERSION=	0.7.9
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX?= -azure

MAINTAINER=	honzhan@microsoft.com
COMMENT=	Init scripts for use on cloud images

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	dmidecode>0:sysutils/dmidecode \
		e2fsprogs>0:sysutils/e2fsprogs \
		${PYTHON_PKGNAMEPREFIX}boto>0:devel/py-boto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cheetah>0:devel/py-cheetah@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>0:devel/py-prettytable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}serial>0:comms/py-serial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>0:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpatch>0:devel/py-jsonpatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpointer>0:devel/py-jsonpointer@${PY_FLAVOR}

ETCDIR=		${PREFIX}/etc/cloud

USES=		python:2.7 shebangfix
SHEBANG_FILES=	tools/validate-yaml.py tools/read-dependencies \
		tools/read-version tools/hacking.py
USE_PYTHON=	autoplist distutils

PYDISTUTILS_INSTALLARGS+=	"--init-system=sysvinit_freebsd"

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	currently depends on dmidecode which is x86-only

PLIST_DIRS=	/var/lib/cloud /var/lib

post-patch:
	${REINPLACE_CMD} -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s,/etc/,${PREFIX}/etc/,g" \
		${WRKSRC}/cloudinit/settings.py

post-build:
	@cd ${WRKSRC} ; ${MV} config/cloud.cfg-freebsd config/cloud.cfg

post-install:
	${MKDIR} ${STAGEDIR}/var/lib/cloud

.include <bsd.port.mk>
