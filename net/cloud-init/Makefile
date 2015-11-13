# $FreeBSD$

PORTNAME=	cloud-init
PORTVERSION=	0.7.6
CATEGORIES=	net python
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	harm@weites.com
COMMENT=	Init scripts for use on cloud images

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dmidecode>0:${PORTSDIR}/sysutils/dmidecode \
		sudo>0:${PORTSDIR}/security/sudo \
		gpart>0:${PORTSDIR}/sysutils/gpart \
		${PYTHON_PKGNAMEPREFIX}boto>0:${PORTSDIR}/devel/py-boto \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}prettytable>0:${PORTSDIR}/devel/py-prettytable \
		${PYTHON_PKGNAMEPREFIX}configobj>0:${PORTSDIR}/devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}argparse>0:${PORTSDIR}/devel/py-argparse \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}serial>0:${PORTSDIR}/comms/py-serial \
		${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}oauth>0:${PORTSDIR}/net/py-oauth \
		${PYTHON_PKGNAMEPREFIX}jsonpatch>0:${PORTSDIR}/devel/py-jsonpatch \
		${PYTHON_PKGNAMEPREFIX}jsonpointer>0:${PORTSDIR}/devel/py-jsonpointer

ETCDIR=		${PREFIX}/etc/cloud

USES=		python:2.7 shebangfix
SHEBANG_FILES=	tools/validate-yaml.py tools/read-dependencies \
		tools/read-version tools/hacking.py
USE_PYTHON=	autoplist distutils

PYDISTUTILS_INSTALLARGS+=	"--init-system=sysvinit_freebsd"

post-build:
	@cd ${WRKSRC} && ${MV} config/cloud.cfg-freebsd config/cloud.cfg

.include <bsd.port.mk>
