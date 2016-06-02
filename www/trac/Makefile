# Created by: Kuei-Feng Li <thinker@branda.to>
# $FreeBSD$

PORTNAME=	trac
PORTVERSION=	1.0.9
CATEGORIES=	www devel python
MASTER_SITES=	http://ftp.edgewall.com/pub/trac/ \
		ftp://ftp.edgewall.com/pub/trac/
DISTNAME=	Trac-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced wiki and issue tracking system for software projects

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=0.9.5:devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.6:textproc/py-genshi
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=0.9.5:devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.6:textproc/py-genshi

USES=		python:-2.7 shebangfix
SHEBANG_FILES=	contrib/cgi-bin/trac.fcgi contrib/cgi-bin/trac.cgi \
		trac/tests/functional/better_twill.py trac/tests/functional/tester.py \
		trac/tests/functional/testenv.py trac/tests/functional/compat.py \
		trac/tests/functional/__init__.py contrib/emailfilter.py \
		contrib/checkwiki.py contrib/htpasswd.py
USE_PYTHON=	distutils autoplist
USE_RC_SUBR=	tracd
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

PORTEXAMPLES=	*
PORTDATA=	*

OPTIONS_DEFINE=		DOCUTILS PYGMENTS TZ SVN EXAMPLES
OPTIONS_DEFAULT=	DOCUTILS PYGMENTS TZ SVN SQLITE
OPTIONS_RADIO=		DATABASE
OPTIONS_RADIO_DATABASE=	PGSQL SQLITE
DOCUTILS_DESC=		Allow additional text markup
PYGMENTS_DESC=		Use generic syntax highlighter
TZ_DESC=		Process Time Zones

DOCUTILS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0.3.9:textproc/py-docutils
PYGMENTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments
TZ_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3
SVN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}subversion>0:devel/py-subversion

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/cgi-bin/* ${STAGEDIR}${DATADIR}/cgi-bin

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/sample-plugins
	${FIND} ${WRKSRC}/contrib -type f -maxdepth 1 -exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR}/ \;
	(cd ${WRKSRC}/sample-plugins && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/sample-plugins)

.include <bsd.port.mk>
