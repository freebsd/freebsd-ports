PORTNAME=	sabnzbdplus
DISTVERSION=	3.3.0
PORTEPOCH=	1
CATEGORIES=	news
MASTER_SITES=	https://github.com/sabnzbd/sabnzbd/releases/download/${DISTVERSION}/
DISTNAME=	SABnzbd-${DISTVERSION}-src

MAINTAINER=	james@french.id.au
COMMENT=	Web-interface based binary newsgrabber in python, with nzb support

LICENSE=	BSD2CLAUSE BSD3CLAUSE GPLv2+ ISCL MIT PSFL
LICENSE_COMB=	multi

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah3>=0:devel/py-cheetah3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cherrypy>=8.9.1:www/py-cherrypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cheroot>=0:www/py-cheroot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>=6.0.0:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portend>=0:net/py-portend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sabyenc3>=0:news/py-sabyenc3@${PY_FLAVOR} \
		par2repair:archivers/par2cmdline \
		unrar:archivers/unrar

USES=		python:3.6+ shebangfix gettext
USE_RC_SUBR=	sabnzbd

SHEBANG_FILES=	SABnzbd.py tools/msgfmt.py

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

WRKSRC=		${WRKDIR}/SABnzbd-${DISTVERSION}

USERS=		_sabnzbd
GROUPS=		_sabnzbd

PORTDOCS=	COPYRIGHT.txt \
		INSTALL.txt \
		ISSUES.txt \
		README.mkd

OPTIONS_DEFINE=	7ZIP SSL DOCS NOTIFY2 DBUS PYGOBJECT
OPTIONS_DEFAULT=	7ZIP SSL
7ZIP_DESC=	Needed for unpacking 7-Zip posts
DBUS_DESC=	DBUS support for system power management
NOTIFY2_DESC=	Notify2 support
PYGOBJECT_DESC=	PyGObject support for system tray icon (requires cairo)

7ZIP_RUN_DEPENDS=	7za:archivers/p7zip
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR}
NOTIFY2_IMPLIES=	DBUS
NOTIFY2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notify2>=0:devel/py-notify2@${PY_FLAVOR}
PYGOBJECT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>=3.10.2:devel/py-gobject3@${PY_FLAVOR}
SSL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e "s:%%DATADIR%%:'${DATADIR}':g" \
		 ${WRKSRC}/SABnzbd.py

# Generate locale files
do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} tools/make_mo.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/SABnzbd.py ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sabnzbd
	cd ${WRKSRC}/sabnzbd && ${COPYTREE_SHARE} \* ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sabnzbd
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in email icons interfaces locale po tools
	@${MKDIR} ${STAGEDIR}${DATADIR}/${i}
	cd ${WRKSRC}/${i} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/${i}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
