PORTNAME=	ansible
DISTVERSION=	g20200803
PORTEPOCH=	1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-${_LIBRARY}

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Ansible module to load kernel modules or update /boot/loader.conf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansible>0:sysutils/ansible@${PY_FLAVOR}

USES=		python shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	dlundgren
GH_PROJECT=	ansible-freebsd-modules
GH_TAGNAME=	537984b53018e36c2511132c3c66ac762f8b36dd
SHEBANG_FILES=	library/${_LIBRARY}

NO_ARCH=	yes
NO_BUILD=	yes

_LIBRARY?=	kld
_ANSIBLE_MOD=	share/${PYTHON_PKGNAMEPREFIX}ansible/plugins/modules

PLIST_FILES=	${_ANSIBLE_MOD}/${_LIBRARY}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${_ANSIBLE_MOD}
	${INSTALL_SCRIPT} ${WRKSRC}/library/${_LIBRARY} \
		${STAGEDIR}${PREFIX}/${_ANSIBLE_MOD}/${_LIBRARY}

.include <bsd.port.mk>
