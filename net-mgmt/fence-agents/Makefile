PORTNAME=	fence-agents
PORTVERSION=	4.12.1
DISTVERSIONPREFIX=v
CATEGORIES=	net-mgmt

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	OCF Compliant Fence Agents
WWW=		https://github.com/ClusterLabs/fence-agents

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycurl>0:ftp/py-pycurl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycurl>0:ftp/py-pycurl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		autoreconf gmake libtool pkgconfig python

USE_GITHUB=	yes
GH_ACCOUNT=	ClusterLabs

GNU_CONFIGURE=	yes
CONFLICTS=	heartbeat

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
			xsltproc:textproc/libxslt

post-patch:
	echo "echo -n ${PORTVERSION}" > ${WRKSRC}/make/git-version-gen

.include <bsd.port.mk>
