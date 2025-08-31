PORTNAME=	sabnzbd
DISTVERSION=	4.5.3
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
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cheetah3>=0:devel/py-cheetah3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cheroot>=0:www/py-cheroot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cherrypy>=8.9.1:www/py-cherrypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>=6.0.0:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}guessit>0:multimedia/py-guessit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portend>=0:net/py-portend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}puremagic>0:sysutils/py-puremagic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybonjour>0:dns/py-pybonjour@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>0:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rarfile>0:archivers/py-rarfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sabctools>=8.2.0<8.3:news/py-sabctools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		par2cmdline-turbo>0:archivers/par2cmdline-turbo \
		unrar:archivers/unrar

USES=		python shebangfix
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	SABnzbd.py

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

WRKSRC=		${WRKDIR}/SABnzbd-${DISTVERSION}

USERS=		_${PORTNAME}
GROUPS=		_${PORTNAME}

PORTDOCS=	COPYRIGHT.txt INSTALL.txt ISSUES.txt README.mkd

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
NOTIFY2_IMPLIES=	DBUS
NOTIFY2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notify2>=0:devel/py-notify2@${PY_FLAVOR}
PYGOBJECT_USES=		gnome
PYGOBJECT_USE=		gnome=pygobject3:run
SSL_USE=		PYTHON=cryptography

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
