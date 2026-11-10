PORTNAME=	sabnzbd
DISTVERSION=	5.1.3
CATEGORIES=	news
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	SABnzbd-${DISTVERSION}-src

MAINTAINER=	nick@kirby.cx
COMMENT=	Web-interface based binary newsgrabber in python, with nzb support
WWW=		https://sabnzbd.org/

LICENSE=	GPLv2+ MIT WTFPL
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYRIGHT.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apprise>0:net-im/py-apprise@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}babelfish>=0.6.1:devel/py-babelfish@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=2.1.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cheetah3>=0:devel/py-cheetah3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cheroot>=0:www/py-cheroot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cherrypy>=8.9.1:www/py-cherrypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>=6.0.0:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}guessit>0:multimedia/py-guessit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hachoir>0:devel/py-hachoir@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.classes>=3.4.0:devel/py-jaraco.classes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.collections>=5.0.0:devel/py-jaraco.collections@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.context>=4.3.0:devel/py-jaraco.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.functools>=4.6.0:devel/py-jaraco.functools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.text>=3.8.1:devel/py-jaraco.text@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>=11.1.0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>=3.11.9:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paho-mqtt>=2.1.0:net/py-paho-mqtt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portend>=0:net/py-portend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}puremagic>0:sysutils/py-puremagic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycparser>=3.0:devel/py-pycparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>0:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.9.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2026.2,1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rarfile>0:archivers/py-rarfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rebulk>=6.0.1:devel/py-rebulk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sabctools>=9.6.3:news/py-sabctools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sgmllib3k>=1.0.0:devel/py-sgmllib3k@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six=1.17.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tempora>=5.8.1:devel/py-tempora@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zc.lockfile>=4.0:devel/py-zc.lockfile@${PY_FLAVOR} \
		par2cmdline-turbo>0:archivers/par2cmdline-turbo \
		unrar:archivers/unrar
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>=0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flaky>=0:devel/py-flaky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyfakefs>=0:filesystems/py-pyfakefs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-httpbin>=0:devel/py-pytest-httpbin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest_httpserver>=0:devel/py-pytest_httpserver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}selenium>=0:www/py-selenium@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tavalidate>=0:devel/py-tavalidate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tavern>=0:devel/py-tavern@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0:devel/py-xmltodict@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pytest
# 13345 passed, 41 skipped, 28 deselected, 2 xfailed, 1 xpassed, 8 warnings
# Selenium has no FreeBSD driver, TestWiki needs network and extract_pot
# needs builder/ (not in the tarball)
PYTEST_IGNORED_TESTS=	TestBasicPages TestConfigCategories TestConfigLogin \
			TestConfigRSS TestConfigServers TestDaemonizing \
			TestDownloadFlow TestDownloadSorting TestQueueRepair \
			TestShowLogging TestWiki test_extract_pot
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	SABnzbd.py

TEST_ARGS=	tests

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

WRKSRC=		${WRKDIR}/SABnzbd-${DISTVERSION}

USERS=		_${PORTNAME}
GROUPS=		_${PORTNAME}

PORTDOCS=	COPYRIGHT.txt ISSUES.txt README.mkd

OPTIONS_DEFINE=		7ZIP DBUS DOCS NLS NOTIFY2 PYGOBJECT SSL
OPTIONS_DEFAULT=	7ZIP SSL
OPTIONS_SUB=		yes
7ZIP_DESC=		Needed for unpacking 7-Zip posts
DBUS_DESC=		DBUS support for system power management
NOTIFY2_DESC=		Notify2 support
PYGOBJECT_DESC=		PyGObject support for system tray icon (requires cairo)

7ZIP_RUN_DEPENDS=	7zz:archivers/7-zip
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR}
NLS_USES=		gettext-tools
NLS_VARS_OFF=		PYTEST_IGNORED_TESTS+=test_api_translate
NOTIFY2_IMPLIES=	DBUS
NOTIFY2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notify2>=0:devel/py-notify2@${PY_FLAVOR}
PYGOBJECT_USES=		gnome
PYGOBJECT_USE=		GNOME=pygobject3:run
SSL_USE=		PYTHON=cryptography

post-extract:
	@${PRINTF} '[pytest]\nmarkers =\n\tconfig\n\tplatform\n\tfake_fs\n' > ${WRKSRC}/pytest.ini

post-patch:
	@${REINPLACE_CMD} -e "s:%%DATADIR%%:'${DATADIR}':g" ${WRKSRC}/SABnzbd.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/SABnzbd.py ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} && \
		${COPYTREE_SHARE} "icons interfaces" ${STAGEDIR}${DATADIR})

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-NLS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "email locale" ${STAGEDIR}${DATADIR})

post-install-NLS-off:
	${MKDIR} ${STAGEDIR}${DATADIR}/email
	${INSTALL_DATA} ${WRKSRC}/email/*-en.tmpl ${STAGEDIR}${DATADIR}/email

.include <bsd.port.mk>
