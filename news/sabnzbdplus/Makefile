# $FreeBSD$

PORTNAME=	sabnzbdplus
PORTVERSION=	2.3.9
CATEGORIES=	news

MAINTAINER=	joshruehlig@gmail.com
COMMENT=	Web-interface based binary newsgrabber in python, with nzb support

LICENSE=	BSD2CLAUSE BSD3CLAUSE GPLv2+ ISCL MIT PSFL
LICENSE_COMB=	multi

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	cheetah:devel/py-cheetah@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/pythonutils/configobj.py:devel/py-utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python:2.7 shebangfix

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

OPTIONS_DEFINE=	PAR2CMDLINE UNRAR 7ZIP FEEDPARSER YENC SSL DOCS
OPTIONS_DEFAULT=	PAR2CMDLINE UNRAR 7ZIP FEEDPARSER YENC SSL
PAR2CMDLINE_DESC=	Required for postprocessing of par files
7ZIP_DESC=	Needed for unpacking 7-Zip posts
FEEDPARSER_DESC=	rss-feed support
YENC_DESC=	yenc support

PAR2CMDLINE_RUN_DEPENDS=	par2repair:archivers/par2cmdline-tbb
FEEDPARSER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=0:textproc/py-feedparser@${PY_FLAVOR}
YENC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sabyenc>=3.3.1:news/py-sabyenc@${PY_FLAVOR}
SSL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR}
UNRAR_RUN_DEPENDS=	unrar:archivers/unrar
7ZIP_RUN_DEPENDS=	7za:archivers/p7zip

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
.for i in cherrypy gntp interfaces locale po tools util
	@${MKDIR} ${STAGEDIR}${DATADIR}/${i}
	cd ${WRKSRC}/${i} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/${i}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
