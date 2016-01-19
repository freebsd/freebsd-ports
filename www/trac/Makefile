# Created by: Kuei-Feng Li <thinker@branda.to>
# $FreeBSD$

PORTNAME=	trac
PORTVERSION=	1.0.9
CATEGORIES=	www devel python
MASTER_SITES=	http://ftp.edgewall.com/pub/trac/ \
		ftp://ftp.edgewall.com/pub/trac/
DISTNAME=	Trac-${PORTVERSION}

MAINTAINER=	antont@inbox.lv
COMMENT=	Enhanced wiki and issue tracking system for software projects

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=0.9.5:${PORTSDIR}/devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.6:${PORTSDIR}/textproc/py-genshi
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=0.9.5:${PORTSDIR}/devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.6:${PORTSDIR}/textproc/py-genshi

OPTIONS_DEFINE=		DOCUTILS PYGMENTS TZ SVN
OPTIONS_DEFAULT=	DOCUTILS PYGMENTS TZ SVN SQLITE
OPTIONS_RADIO=		DATABASE
OPTIONS_RADIO_DATABASE=	PGSQL SQLITE
DOCUTILS_DESC=		Allow additional text markup
PYGMENTS_DESC=		Use generic syntax highlighter
TZ_DESC=		Process Time Zones

DOCUTILS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0.3.9:${PORTSDIR}/textproc/py-docutils
PYGMENTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:${PORTSDIR}/textproc/py-pygments
TZ_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:${PORTSDIR}/databases/py-psycopg2
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
SVN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}subversion>0:${PORTSDIR}/devel/py-subversion

PORTEXAMPLES=		*
PORTDATA=		*
MAKE_ENV=		HOME=/dev/null

USES=			python:-2.7 shebangfix
SHEBANG_FILES=		contrib/cgi-bin/trac.fcgi contrib/cgi-bin/trac.cgi \
			trac/tests/functional/better_twill.py trac/tests/functional/tester.py \
			trac/tests/functional/testenv.py trac/tests/functional/compat.py \
			trac/tests/functional/__init__.py contrib/emailfilter.py \
			contrib/checkwiki.py contrib/htpasswd.py
USE_PYTHON=		distutils autoplist
USE_RC_SUBR=		tracd
SUB_LIST+=		PYTHON_CMD=${PYTHON_CMD}

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/sample-plugins
	${FIND} ${WRKSRC}/contrib -type f -maxdepth 1 -exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR}/ \;
	(cd ${WRKSRC}/sample-plugins && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/sample-plugins)
	@${MKDIR} ${STAGEDIR}${DATADIR}/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/cgi-bin/* ${STAGEDIR}${DATADIR}/cgi-bin

.include <bsd.port.mk>
