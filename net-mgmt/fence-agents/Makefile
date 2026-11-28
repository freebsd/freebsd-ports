PORTNAME=	fence-agents
DISTVERSIONPREFIX=	v
DISTVERSION=	4.17.0
CATEGORIES=	net-mgmt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCF Compliant Fence Agents
WWW=		https://github.com/ClusterLabs/fence-agents

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+  =	${WRKSRC}/doc/COPYING.applications
LICENSE_FILE_LGPL21+ =	${WRKSRC}/doc/COPYING.libraries

BUILD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycurl>0:ftp/py-pycurl@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR}

USES=		autoreconf cpe gmake libtool pkgconfig python shebangfix

CPE_VENDOR=	clusterlabs

USE_GITHUB=	yes
GH_ACCOUNT=	ClusterLabs

SHEBANG_FILES=	agents/manual/fence_ack_manual.in

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFLICTS=	heartbeat

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl
MANPAGES_USES=	gnome
MANPAGES_USE=	GNOME=libxslt:build

post-patch:
	echo "echo -n ${DISTVERSION}" > ${WRKSRC}/make/git-version-gen

do-test:
	@cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} fence_testing_test.py

.include <bsd.port.mk>
