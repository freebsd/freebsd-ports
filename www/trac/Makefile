# Created by: Kuei-Feng Li <thinker@branda.to>
# $FreeBSD$

PORTNAME=	trac
PORTVERSION=	1.2.5
CATEGORIES=	www devel python
MASTER_SITES=	http://ftp.edgewall.com/pub/trac/ \
		ftp://ftp.edgewall.com/pub/trac/
DISTNAME=	Trac-${PORTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Enhanced wiki and issue tracking system for software projects

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=2.8.0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.7.3:textproc/py-genshi@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=2.8.0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.7.3:textproc/py-genshi@${PY_FLAVOR}

CONFLICTS_INSTALL=	trac-devel

PORTSCOUT=	limit:^1\.2\.[0-9]*

USES=		python:2.7 shebangfix
SHEBANG_FILES=	trac/tests/functional/better_twill.py trac/tests/functional/tester.py \
		trac/tests/functional/testenv.py trac/tests/functional/compat.py \
		trac/tests/functional/__init__.py contrib/emailfilter.py \
		contrib/checkwiki.py contrib/htpasswd.py
USE_PYTHON=	distutils autoplist
USE_RC_SUBR=	tracd
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

PORTEXAMPLES=	*
PORTDATA=	*

NO_ARCH=	yes

OPTIONS_DEFINE=		DOCUTILS PYGMENTS TZ SVN EXAMPLES
OPTIONS_DEFAULT=	DOCUTILS PYGMENTS TZ SVN SQLITE
OPTIONS_RADIO=		DATABASE
OPTIONS_RADIO_DATABASE=	PGSQL SQLITE
DOCUTILS_DESC=		Allow additional text markup
PYGMENTS_DESC=		Use generic syntax highlighter
TZ_DESC=		Process Time Zones

DOCUTILS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0.15.2:textproc/py-docutils@${PY_FLAVOR}
PYGMENTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=2.5.2:textproc/py-pygments@${PY_FLAVOR}
TZ_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR}
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
SVN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}subversion>0:devel/py-subversion@${PY_FLAVOR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/sample-plugins
	${FIND} ${WRKSRC}/contrib -type f -maxdepth 1 -exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR}/ \;
	(cd ${WRKSRC}/sample-plugins && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/sample-plugins)

.include <bsd.port.mk>
