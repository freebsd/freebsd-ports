# Created by: Hizbulin Ildar <hizel@vyborg.ru>
# $FreeBSD$

PORTNAME=	supervisor
PORTVERSION=	3.3.3
PORTEPOCH=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hizel@vyborg.ru
COMMENT=	System for controlling process state under UNIX

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meld3>=0.6.5:www/py-meld3@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0.5.0:devel/py-mock@${FLAVOR}

PORTDOCS=	*.txt *.rst

NO_ARCH=	yes

USES=		python:2.7 shebangfix
USE_PYTHON=	distutils autoplist
PIDDIR?=	/var/run/supervisor

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		PIDDIR=${PIDDIR}
PLIST_SUB=	PIDDIR=${PIDDIR}
USE_RC_SUBR=	supervisord

SHEBANG_FILES=	supervisor/scripts/*.py supervisor/tests/fixtures/*.py
python_OLD_CMD=	"/usr/bin/env python"
python_OLD_CMD+=	"<<PYTHON>>"

post-patch:
	@${REINPLACE_CMD} -e 's!%%PREFIX%%!${PREFIX}!' ${WRKSRC}/supervisor/options.py

post-install:
	${INSTALL_DATA} ${FILESDIR}/supervisord.conf.sample ${STAGEDIR}${PREFIX}/etc
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
