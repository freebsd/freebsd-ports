# $FreeBSD$

PORTNAME=	sabnzbdplus
PORTVERSION=	3.0.0
CATEGORIES=	news

MAINTAINER=	james@french.id.au
COMMENT=	Web-interface based binary newsgrabber in python, with nzb support

LICENSE=	BSD2CLAUSE BSD3CLAUSE GPLv2+ ISCL MIT PSFL
LICENSE_COMB=	multi

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah3>=0:devel/py-cheetah3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cherrypy>=8.9.1:www/py-cherrypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portend>=0:net/py-portend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python:3.5+ shebangfix gettext

USE_GITHUB=	yes
GH_ACCOUNT=	sabnzbd
GH_PROJECT=	sabnzbd

SHEBANG_FILES=	SABnzbd.py tools/msgfmt.py

NO_ARCH=	yes
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}
SUB_FILES=	pkg-message
USE_RC_SUBR=	sabnzbd

PORTDOCS=	ABOUT.txt \
		COPYRIGHT.txt \
		INSTALL.txt \
		ISSUES.txt \
		README.mkd

USERS=		_sabnzbd
GROUPS=		_sabnzbd

OPTIONS_DEFINE=	PAR2CMDLINE UNRAR 7ZIP FEEDPARSER YENC SSL DOCS NOTIFY2 DBUS PYGOBJECT
OPTIONS_DEFAULT=	PAR2CMDLINE UNRAR 7ZIP FEEDPARSER YENC SSL
PAR2CMDLINE_DESC=	Required for postprocessing of par files
7ZIP_DESC=	Needed for unpacking 7-Zip posts
FEEDPARSER_DESC=	RSS feed support
YENC_DESC=	yenc support
NOTIFY2_DESC=	Notify2 support
DBUS_DESC=	DBUS support for system power management
PYGOBJECT_DESC=	PyGObject support for system tray icon (requires cairo)

PAR2CMDLINE_RUN_DEPENDS=	par2repair:archivers/par2cmdline-tbb
FEEDPARSER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=0:textproc/py-feedparser@${PY_FLAVOR}
YENC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sabyenc3>=0:news/py-sabyenc3@${PY_FLAVOR}
SSL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR}
UNRAR_RUN_DEPENDS=	unrar:archivers/unrar
7ZIP_RUN_DEPENDS=	7za:archivers/p7zip
NOTIFY2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notify2>=0:devel/py-notify2@${PY_FLAVOR}
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR}
PYGOBJECT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>=3.10.2:devel/py-gobject3@${PY_FLAVOR}

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
