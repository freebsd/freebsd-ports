# $FreeBSD$

PORTNAME=	ansible
PORTVERSION?=	2.5.2
PORTREVISION?=	1
CATEGORIES=	sysutils python
MASTER_SITES=	http://releases.ansible.com/ansible/

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Radically simple IT automation

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS?=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>0:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

CONFLICTS?=	ansible1-* ansible23-* ansible24-*

EXTRA_PATCHES?=	${FILESDIR}/extra-patch-sesu

NO_ARCH=	yes
USES?=		cpe python
USE_PYTHON=	autoplist distutils noflavors
CPE_VENDOR=	ansibleworks

SUB_FILES=	pkg-message
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PLIST_FILES?=	man/man1/ansible-config.1.gz \
		man/man1/ansible-console.1.gz \
		man/man1/ansible-doc.1.gz \
		man/man1/ansible-galaxy.1.gz \
		man/man1/ansible-inventory.1.gz \
		man/man1/ansible-playbook.1.gz \
		man/man1/ansible-pull.1.gz \
		man/man1/ansible-vault.1.gz \
		man/man1/ansible.1.gz

PORTEXAMPLES=	ansible.cfg hosts

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${FIND} ${WRKSRC} -type f -print0 | ${XARGS} -0 ${REINPLACE_CMD} \
		-e 's|/etc/ansible|${ETCDIR}|g' \
		-e 's|/usr/share/ansible|${DATADIR}|g'

post-install:
	@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/*.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/ansible.cfg ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/hosts ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
