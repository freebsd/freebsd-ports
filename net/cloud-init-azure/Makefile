# $FreeBSD$

PORTNAME=	cloud-init
PORTVERSION=	0.7.9
CATEGORIES=	net python
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX?= -azure

MAINTAINER=	honzhan@microsoft.com
COMMENT=	Init scripts for use on cloud images

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dmidecode>0:sysutils/dmidecode \
		e2fsprogs>0:sysutils/e2fsprogs \
		python>0:lang/python \
		${PYTHON_PKGNAMEPREFIX}boto>0:devel/py-boto \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}cheetah>0:devel/py-cheetah \
		${PYTHON_PKGNAMEPREFIX}prettytable>0:devel/py-prettytable \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}serial>0:comms/py-serial \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}oauthlib>0:security/py-oauthlib \
		${PYTHON_PKGNAMEPREFIX}jsonpatch>0:devel/py-jsonpatch \
		${PYTHON_PKGNAMEPREFIX}jsonpointer>0:devel/py-jsonpointer

ETCDIR=		${PREFIX}/etc/cloud

USES=		python:2.7 shebangfix
SHEBANG_FILES=	tools/validate-yaml.py tools/read-dependencies \
		tools/read-version tools/hacking.py
USE_PYTHON=	autoplist distutils

PYDISTUTILS_INSTALLARGS+=	"--init-system=sysvinit_freebsd"

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	currently depends on dmidecode which is x86-only

PLIST_DIRS=	/var/lib/cloud

post-patch:
	${REINPLACE_CMD} -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s,/etc/,${PREFIX}/etc/,g" \
		${WRKSRC}/cloudinit/settings.py

post-build:
	@cd ${WRKSRC} ; ${MV} config/cloud.cfg-freebsd config/cloud.cfg

post-install:
	${MKDIR} ${STAGEDIR}/var/lib/cloud

.include <bsd.port.mk>
