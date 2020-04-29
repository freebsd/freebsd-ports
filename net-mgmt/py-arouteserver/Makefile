# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arouteserver
PORTVERSION=	0.25.0
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool to automatically build configurations for BGP route servers

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash>0:shells/bash \
		bgpq4>0:net-mgmt/bgpq4 \
		ca_root_nss>0:security/ca_root_nss \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.9.4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aggregate6>=1.0.12:net-mgmt/py-aggregate6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18.4:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.13:devel/py-yaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.3.7:devel/py-nose@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_FILES=	pierky/arouteserver/config.d/rtt_getter.sh
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipaddr>=2.1.11:devel/py-ipaddr@${PY_FLAVOR}
.endif

post-patch:
	${REINPLACE_CMD} -e 's|#bgpq3_path: "bgpq3"|bgpq3_path: "bgpq4"|' \
		${WRKSRC}/pierky/arouteserver/config.d/arouteserver.yml

do-test:
	@(cd ${WRKSRC} && ${SETENV} nosetests -vs --tests=tests/external_resources/)

.include <bsd.port.post.mk>
