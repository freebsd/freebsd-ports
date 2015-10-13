# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PORTNAME=	ansible
PORTVERSION=	1.9.4
CATEGORIES=	sysutils python
MASTER_SITES=	http://releases.ansible.com/ansible/

MAINTAINER=	lifanov@mail.lifanov.com
COMMENT=	Radically simple IT automation

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:${PORTSDIR}/security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:${PORTSDIR}/devel/py-Jinja2

OPTIONS_DEFINE=	EXAMPLES

NO_ARCH=	yes
USES=		cpe python:2 shebangfix
USE_PYTHON=	autoplist distutils
python_CMD=	${LOCALBASE}/bin/python
SHEBANG_FILES=	lib/ansible/runner/action_plugins/synchronize.py \
		lib/ansible/modules/core/*/*.py \
		lib/ansible/modules/core/*/*/*.py \
		lib/ansible/modules/extras/*/*.py \
		lib/ansible/modules/extras/*/*/*.py
CPE_VENDOR=	ansibleworks

SUB_FILES=	pkg-message

PLIST_FILES+=	man/man1/ansible-doc.1.gz \
		man/man1/ansible-galaxy.1.gz \
		man/man1/ansible-playbook.1.gz \
		man/man1/ansible-pull.1.gz \
		man/man1/ansible-vault.1.gz \
		man/man1/ansible.1.gz

PORTEXAMPLES=	ansible.cfg hosts

post-patch:
.for f in bin/ansible-galaxy docs/man/man1/ansible-galaxy.1 \
	docs/man/man1/ansible-playbook.1 docs/man/man1/ansible.1 \
	examples/ansible.cfg examples/hosts lib/ansible/constants.py \
	lib/ansible/module_utils/urls.py lib/ansible/modules/core/system/setup.py \
	lib/ansible/playbook/__init__.py lib/ansible/runner/__init__.py
	@${REINPLACE_CMD} -e 's|/etc/ansible|${ETCDIR}|' ${WRKSRC}/${f}
.endfor

.for f in docs/man/man1/ansible-playbook.1 docs/man/man1/ansible.1 \
	examples/ansible.cfg lib/ansible/constants.py \
	lib/ansible/playbook/__init__.py lib/ansible/runner/__init__.py \
	@${REINPLACE_CMD} -e 's|/usr/share/ansible|${DATADIR}|' ${WRKSRC}/${f}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/*.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/ansible.cfg ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/hosts ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
