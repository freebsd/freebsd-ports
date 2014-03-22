# $FreeBSD$

PORTNAME=	ansible
PORTVERSION=	1.5.3
CATEGORIES=	sysutils python

MAINTAINER=	lifanov@mail.lifanov.com
COMMENT=	Simple ssh-based configuration management and orchestration system

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:${PORTSDIR}/security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:${PORTSDIR}/devel/py-Jinja2

OPTIONS_DEFINE=		ACCELERATE EXAMPLES
OPTIONS_DEFAULT=	ACCELERATE

ACCELERATE_DESC=	Enable Accelerated Mode (Uses pycrypto and keyczar)
ACCELERATE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto \
			${PYTHON_PKGNAMEPREFIX}keyczar>0:${PORTSDIR}/security/py-keyczar

USE_GITHUB=	yes
GH_ACCOUNT=	ansible
GH_TAGNAME=	v${DISTVERSION}
GH_COMMIT=	6ae58a9

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

USES=		shebangfix
SHEBANG_FILES=	library/*/* \
		lib/ansible/runner/action_plugins/synchronize.py

SUB_FILES=	pkg-message
PLIST_FILES+=	man/man1/ansible-doc.1.gz \
		man/man1/ansible-playbook.1.gz \
		man/man1/ansible-pull.1.gz \
		man/man1/ansible.1.gz

PORTEXAMPLES=	ansible.cfg hosts

post-patch:
	@${REINPLACE_CMD} -i -e "s|/etc/ansible|${ETCDIR}|" \
		${WRKSRC}/bin/ansible-galaxy \
		${WRKSRC}/docs/man/man1/ansible-playbook.1 \
		${WRKSRC}/docs/man/man1/ansible.1 \
		${WRKSRC}/examples/ansible.cfg \
		${WRKSRC}/examples/hosts \
		${WRKSRC}/lib/ansible/constants.py \
		${WRKSRC}/lib/ansible/playbook/__init__.py \
		${WRKSRC}/lib/ansible/runner/__init__.py \
		${WRKSRC}/library/system/setup
	@${REINPLACE_CMD} -i -e "s|/usr/share/ansible|${DATADIR}|" \
		${WRKSRC}/docs/man/man1/ansible-playbook.1 \
		${WRKSRC}/docs/man/man1/ansible.1 \
		${WRKSRC}/examples/ansible.cfg \
		${WRKSRC}/lib/ansible/constants.py \
		${WRKSRC}/lib/ansible/playbook/__init__.py \
		${WRKSRC}/lib/ansible/runner/__init__.py
	@${RM}	${WRKSRC}/library/system/setup-e

post-install:
	@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/*.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/ansible.cfg ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/hosts ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
