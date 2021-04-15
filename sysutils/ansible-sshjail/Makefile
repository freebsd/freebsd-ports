PORTNAME=	ansible-sshjail
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0-30
DISTVERSIONSUFFIX=	-g981674f
CATEGORIES=	sysutils

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Ansible connector for remote jails

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansible>0:sysutils/ansible@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes

GH_ACCOUNT=	austinhyde

NO_ARCH=	yes
NO_BUILD=	yes

ANSIBLE_MOD=	share/${PYTHON_PKGNAMEPREFIX}ansible/plugins/connection

PLIST_FILES=	${ANSIBLE_MOD}/sshjail.py

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${ANSIBLE_MOD}
	${INSTALL_SCRIPT} ${WRKSRC}/sshjail.py \
		${STAGEDIR}${PREFIX}/${ANSIBLE_MOD}/sshjail.py

.include <bsd.port.mk>
