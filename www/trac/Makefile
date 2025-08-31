PORTNAME=	trac
DISTVERSION=	1.6
PORTREVISION=	5
CATEGORIES=	www devel python
MASTER_SITES=	http://ftp.edgewall.com/pub/trac/ \
		ftp://ftp.edgewall.com/pub/trac/
DISTNAME=	Trac-${DISTVERSION}

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Enhanced wiki and issue tracking system for software projects
WWW=		https://trac.edgewall.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10:devel/py-Jinja2@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10:devel/py-Jinja2@${PY_FLAVOR}

# some tests are failing with 3.8
USES=		cpe python
CPE_VENDOR=	edgewall

USE_PYTHON=	distutils autoplist
USE_RC_SUBR=	tracd
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

PORTEXAMPLES=	*
PORTDATA=	*

NO_ARCH=	yes

OPTIONS_DEFINE=		DOCUTILS EXAMPLES FCGI GIT PYGMENTS SUBVERSION TEXTILE TZ
OPTIONS_DEFAULT=	DOCUTILS FCGI PYGMENTS SQLITE SUBVERSION TEXTILE TZ
OPTIONS_MULTI=		DATABASE
OPTIONS_MULTI_DATABASE=	MYSQL PGSQL SQLITE
DOCUTILS_DESC=		Allow additional text markup
PYGMENTS_DESC=		Use generic syntax highlighter
TEXTILE_DESC=		Support for the Textile markup
TZ_DESC=		Process Time Zones
FCGI_DESC=		Enable FastCGI support

DOCUTILS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0.14:textproc/py-docutils@${PY_FLAVOR}
PYGMENTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=1.0:textproc/py-pygments@${PY_FLAVOR}
TZ_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR}
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymysql>=0:databases/py-pymysql@${PY_FLAVOR}
.if ${WITH_SUBVERSION_VER:U} == LTS
SUBVERSION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}subversion-lts>=0:devel/py-subversion@${PY_FLAVOR}
.else
SUBVERSION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}subversion>=0:devel/py-subversion@${PY_FLAVOR}
.endif
GIT_RUN_DEPENDS=	git:devel/git
TEXTILE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}textile>0:www/py-textile@${PY_FLAVOR}
FCGI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flup6>0:www/py-flup6@${PY_FLAVOR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/sample-plugins
	${FIND} ${WRKSRC}/contrib -type f -maxdepth 1 -exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR}/ \;
	(cd ${WRKSRC}/sample-plugins && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/sample-plugins)

.include <bsd.port.mk>
