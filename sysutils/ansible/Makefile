# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PORTNAME=	ansible
PORTVERSION?=	2.3.0.0
PORTREVISION?=	2
CATEGORIES=	sysutils python
MASTER_SITES=	http://releases.ansible.com/ansible/

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Radically simple IT automation

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS?=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}jmespath>0:devel/py-jmespath \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml

EXTRA_PATCHES?=	${FILESDIR}/extra-patch-f82d95a

NO_ARCH=	yes
USES?=		cpe python
USE_PYTHON=	autoplist distutils
CPE_VENDOR=	ansibleworks

SUB_FILES=	pkg-message
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PLIST_FILES?=	man/man1/ansible-console.1.gz \
		man/man1/ansible-doc.1.gz \
		man/man1/ansible-galaxy.1.gz \
		man/man1/ansible-playbook.1.gz \
		man/man1/ansible-pull.1.gz \
		man/man1/ansible-vault.1.gz \
		man/man1/ansible.1.gz

PORTEXAMPLES=	ansible.cfg hosts

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
.for f in bin/ansible docs/man/man1/* examples/* lib/ansible/*.py \
	lib/ansible/*/*.py lib/ansible/*/*/*.py lib/ansible/*/*/*/*.py
	@${REINPLACE_CMD} -e 's|/etc/ansible|${ETCDIR}|' ${WRKSRC}/${f}
.endfor

.for f in docs/man/man1/* examples/* lib/ansible/*.py lib/ansible/*/*.py
	@${REINPLACE_CMD} -e 's|/usr/share/ansible|${DATADIR}|' ${WRKSRC}/${f}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/*.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/ansible.cfg ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/hosts ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
