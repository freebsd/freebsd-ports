# Created by: dpejesh@yahoo.com
# $FreeBSD$

PORTNAME=	crmsh
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	net-mgmt python

MAINTAINER=	dpejesh@yahoo.com
COMMENT=	Command-line interface for High-Availability cluster management

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

# Set the build/run depends on setuptools instead of adding distutils to USE_PYTHON
# because the crmsh build uses autotools which then calls setup.py.
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	ClusterLabs

USES=		autoreconf gmake python:2.7 shebangfix
USE_PYTHON=	flavors
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ocf-root=${PREFIX}/lib/ocf
NO_ARCH=	yes

SHEBANG_FILES=	bin/crm \
		scripts/*/*.py \
		test/cib-tests.sh \
		test/evaltest.sh \
		test/list-undocumented-commands.py \
		utils/crm_clean.py \
		utils/crm_pkg.py \
		utils/crm_rpmcheck.py

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	asciidoc:textproc/asciidoc

MANPAGES_BUILD_DEPENDS=	${DOCS_BUILD_DEPENDS}

post-patch:
	${REINPLACE_CMD} 's,%%DATADIR%%,${DATADIR},' ${WRKSRC}/setup.py

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/crm/crm.conf \
		${STAGEDIR}${PREFIX}/etc/crm/crm.conf.sample

.include <bsd.port.mk>
