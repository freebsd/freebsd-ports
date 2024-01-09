PORTNAME=	crmsh
PORTVERSION=	4.5.1
CATEGORIES=	net-mgmt python

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Command-line interface for High-Availability cluster management
WWW=		https://crmsh.github.io

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

# Set the build/run depends on setuptools instead of adding distutils to USE_PYTHON
# because the crmsh build uses autotools which then calls setup.py.
BUILD_DEPENDS=	${PY_SETUPTOOLS}
RUN_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parallax>0:devel/py-parallax@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		autoreconf cpe gmake python shebangfix
CPE_VENDOR=	clusterlabs
USE_GITHUB=	yes
GH_ACCOUNT=	ClusterLabs
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ocf-root=${PREFIX}/lib/ocf

NO_ARCH=	yes

CONFLICTS_INSTALL=	crm114 # bin/crm

SHEBANG_FILES=	bin/crm scripts/*/*.py test/cib-tests.sh test/evaltest.sh \
		test/features/steps/behave_agent.py \
		test/list-undocumented-commands.py test/run-functional-tests \
		test/testcases/confbasic-xml.filter \
		test/update-expected-output.sh utils/crm_clean.py \
		utils/crm_pkg.py utils/crm_rpmcheck.py

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	asciidoc:textproc/asciidoc

MANPAGES_BUILD_DEPENDS=	${DOCS_BUILD_DEPENDS}

post-patch:
	@${REINPLACE_CMD} 's,%%DATADIR%%,${DATADIR},g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/crmsh/corosync.py
	@${REINPLACE_CMD} 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/crmsh/utils.py
	@${REINPLACE_CMD} 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/scripts/health/collect.py
	@${REINPLACE_CMD} 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/utils/crm_init.py

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/crm/crm.conf \
		${STAGEDIR}${PREFIX}/etc/crm/crm.conf.sample

.include <bsd.port.mk>
