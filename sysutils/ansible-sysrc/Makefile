# $FreeBSD$

PORTNAME=	ansible-sysrc
DISTVERSION=	0.1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vulcan@wired.sh
COMMENT=	Ansible module to set sysvars in rc.conf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansible>0:sysutils/ansible@${PY_FLAVOR}

USES=		python shebangfix
SHEBANG_FILES=	library/sysrc

USE_GITHUB=	yes
GH_ACCOUNT=	dlundgren
GH_PROJECT=	ansible-freebsd-modules
GH_TAGNAME=	cf37fc1e16fc03852abc8933e7959b22b51a5c90

NO_ARCH=	yes
NO_BUILD=	yes

ANSIBLE_MOD=	share/${PYTHON_PKGNAMEPREFIX}ansible/plugins/modules

PLIST_FILES=	${ANSIBLE_MOD}/sysrc

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${ANSIBLE_MOD}
	${INSTALL_SCRIPT} ${WRKSRC}/library/sysrc \
		${STAGEDIR}${PREFIX}/${ANSIBLE_MOD}/sysrc

.include <bsd.port.mk>
