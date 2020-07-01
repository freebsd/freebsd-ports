# Created by: Hizbulin Ildar <hizel@vyborg.ru>
# $FreeBSD$

PORTNAME=	supervisor
PORTVERSION=	4.2.0
PORTEPOCH=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thomas@gibfest.dk
COMMENT=	System for controlling process state under UNIX

LICENSE=	REPOZE BSD3CLAUSE MEDUSA
LICENSE_COMB=	multi
LICENSE_NAME_REPOZE=	Repoze License
LICENSE_NAME_MEDUSA=	Medusa License
LICENSE_FILE=	${WRKSRC}/LICENSES.txt
LICENSE_PERMS_REPOZE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_MEDUSA=	dist-mirror pkg-mirror auto-accept

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0.5.0:devel/py-mock@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	distutils autoplist

PIDDIR?=	/var/run/supervisor

NO_ARCH=	yes
PLIST_FILES=	'@sample etc/supervisord.conf.sample'
PLIST_DIRS=	${PIDDIR}

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		PIDDIR=${PIDDIR}
PLIST_SUB=	PIDDIR=${PIDDIR}
USE_RC_SUBR=	supervisord

SHEBANG_FILES=	supervisor/scripts/*.py supervisor/tests/fixtures/*.py
python_OLD_CMD+=	"<<PYTHON>>"

PORTDOCS=	*.txt *.rst

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's!%%PREFIX%%!${PREFIX}!' ${WRKSRC}/supervisor/options.py \
		${WRKSRC}/supervisor/tests/test_options.py

post-install:
	${INSTALL_DATA} ${FILESDIR}/supervisord.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL} -d ${STAGEDIR}${PIDDIR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
