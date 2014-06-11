# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PORTNAME=	ansible
PORTVERSION=	1.6.3
CATEGORIES=	sysutils python
MASTER_SITES=	SF/lifanov-ports-distfiles/sysutils/${PORTNAME}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

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
GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	dffea7f

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

USES=		shebangfix
SHEBANG_FILES=	library/*/* \
		lib/ansible/runner/action_plugins/synchronize.py

SUB_FILES=	pkg-message

PLIST_FILES+=	man/man1/ansible-doc.1.gz \
		man/man1/ansible-galaxy.1.gz \
		man/man1/ansible-playbook.1.gz \
		man/man1/ansible-pull.1.gz \
		man/man1/ansible-vault.1.gz \
		man/man1/ansible.1.gz \
		${DESKTOPDIR}/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png

PORTEXAMPLES=	ansible.cfg hosts

post-patch:
.for f in bin/ansible-galaxy docs/man/man1/ansible-playbook.1 \
	docs/man/man1/ansible.1 examples/ansible.cfg \
	examples/hosts lib/ansible/constants.py \
	lib/ansible/playbook/__init__.py lib/ansible/runner/__init__.py \
	library/system/setup
	@${REINPLACE_CMD} -e 's|/etc/ansible|${ETCDIR}|' ${WRKSRC}/${f}
.endfor

.for f in docs/man/man1/ansible-playbook.1 docs/man/man1/ansible.1 \
	examples/ansible.cfg lib/ansible/constants.py \
	lib/ansible/playbook/__init__.py lib/ansible/runner/__init__.py
	@${REINPLACE_CMD} -e 's|/usr/share/ansible|${DATADIR}|' ${WRKSRC}/${f}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/*.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/ansible.cfg ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/hosts ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
