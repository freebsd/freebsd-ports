# $FreeBSD$

PORTNAME=	ansible
PORTVERSION=	1.3.4
CATEGORIES=	sysutils python
MASTER_SITES=	http://ansibleworks.com/releases/

MAINTAINER=	lifanov@mail.lifanov.com
COMMENT=	Simple ssh-based configuration management and orchestration system

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}paramiko>=0:${PORTSDIR}/security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:${PORTSDIR}/devel/py-Jinja2
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	ACCELERATE EXAMPLES
OPTIONS_DEFAULT=	ACCELERATE

ACCELERATE_DESC=	Enable accelerate mode
ACCELERATE_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}pycrypto>=0:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}keyczar>=0:${PORTSDIR}/security/py-keyczar

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

USES=		shebangfix
SHEBANG_FILES=	${WRKSRC}/library/*/*

SUB_FILES=	pkg-message

PORTEXAMPLES=	ansible.cfg hosts

post-patch-script:
	@${REINPLACE_CMD} -i -e "s|/etc/ansible|${ETCDIR}|" \
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

post-install:
	@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/*.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${MAN3PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/docs/man/man3/*.3 \
		${STAGEDIR}${MAN3PREFIX}/man/man3
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/ansible.cfg ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/hosts ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
