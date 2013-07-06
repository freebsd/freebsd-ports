# $FreeBSD$

PORTNAME=	ansible
PORTVERSION=	1.2.2
CATEGORIES=	sysutils python
MASTER_SITES=	http://ansibleworks.com/releases/

MAINTAINER=	lifanov@mail.lifanov.com
COMMENT=	Simple ssh-based configuration management and orchestration system

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}paramiko>=0:${PORTSDIR}/security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:${PORTSDIR}/devel/py-Jinja2

RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes

USES=		shebangfix
SHEBANG_FILES=	${WRKSRC}/library/*/*

SUB_FILES=	pkg-message
PORTEXAMPLES=	*
MAN1=	ansible-doc.1 ansible-playbook.1 ansible-pull.1 ansible.1

post-patch-script:
	@${REINPLACE_CMD} -e "s|/etc/ansible|${ETCDIR}|" \
		${WRKSRC}/docs/man/man1/ansible-playbook.1 \
		${WRKSRC}/docs/man/man1/ansible.1 \
		${WRKSRC}/examples/ansible.cfg \
		${WRKSRC}/examples/hosts \
		${WRKSRC}/lib/ansible/constants.py \
		${WRKSRC}/lib/ansible/playbook/__init__.py \
		${WRKSRC}/lib/ansible/runner/__init__.py
	@${REINPLACE_CMD} -e "s|/usr/share/ansible|${DATADIR}|" \
		${WRKSRC}/docs/man/man1/ansible-playbook.1 \
		${WRKSRC}/docs/man/man1/ansible.1 \
		${WRKSRC}/examples/ansible.cfg \
		${WRKSRC}/lib/ansible/constants.py \
		${WRKSRC}/lib/ansible/playbook/__init__.py \
		${WRKSRC}/lib/ansible/runner/__init__.py

pre-install-script:
	@(cd ${WRKSRC} && ${FIND} . -type f -name '*.bak' -exec ${RM} {} +)

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/docs/man/man1/,} \
		${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && \
		${COPYTREE_SHARE} \* ${EXAMPLESDIR})
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
