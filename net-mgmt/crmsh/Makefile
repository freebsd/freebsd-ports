# Created by: David Shane Holden <dpejesh@yahoo.com>
# $FreeBSD$

PORTNAME=		crmsh
PORTVERSION=		3.0.4
CATEGORIES=		net-mgmt python

MAINTAINER=		egypcio@FreeBSD.org
COMMENT=		Command-line interface for High-Availability cluster management

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

# Set the build/run depends on setuptools instead of adding distutils to USE_PYTHON
# because the crmsh build uses autotools which then calls setup.py.
BUILD_DEPENDS=		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}parallax>0:devel/py-parallax@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=			autoreconf gmake python:2.7 shebangfix
USE_GITHUB=		yes
GH_ACCOUNT=		ClusterLabs
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-ocf-root=${PREFIX}/lib/ocf

NO_ARCH=		yes

SHEBANG_FILES=		bin/crm \
			scripts/*/*.py \
			test/cib-tests.sh \
			test/evaltest.sh \
			test/list-undocumented-commands.py \
			utils/crm_clean.py \
			utils/crm_pkg.py \
			utils/crm_rpmcheck.py

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	asciidoc:textproc/asciidoc

MANPAGES_BUILD_DEPENDS=	${DOCS_BUILD_DEPENDS}

post-patch:
	@${REINPLACE_CMD} 's,%%DATADIR%%,${DATADIR},g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/crmsh/corosync.py
	@${REINPLACE_CMD} 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/crmsh/utils.py
	@${REINPLACE_CMD} 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/hb_report/hb_report.in
	@${REINPLACE_CMD} 's,%%PYTHON_CMD%%,${PYTHON_CMD},g' ${WRKSRC}/hb_report/hb_report.in
	@${REINPLACE_CMD} 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/hb_report/openais_conf_support.sh
	@${REINPLACE_CMD} 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/hb_report/utillib.sh
	@${REINPLACE_CMD} 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/scripts/health/collect.py
	@${REINPLACE_CMD} 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/utils/crm_init.py

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/crm/crm.conf \
		${STAGEDIR}${PREFIX}/etc/crm/crm.conf.sample

.include <bsd.port.mk>
