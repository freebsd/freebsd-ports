# $FreeBSD$

PORTNAME=	sabnzbdplus
PORTVERSION=	1.0.3
CATEGORIES=	news
MASTER_SITES=	SF
DISTNAME=	SABnzbd-${PORTVERSION}-src

MAINTAINER=	joshruehlig@gmail.com
COMMENT=	Web-interface based binary newsgrabber in python, with nzb support

LICENSE=	BSD2CLAUSE BSD3CLAUSE GPLv2+ ISCL MIT PSFL
LICENSE_COMB=	multi

RUN_DEPENDS=	cheetah:devel/py-cheetah \
		${PYTHON_SITELIBDIR}/pythonutils/configobj.py:devel/py-utils \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3

USES=		gettext python:2.6-2.7

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/SABnzbd-${PORTVERSION}
PLIST_SUB=	PORTNAME=${PORTNAME}
SUB_LIST=	PORTNAME=${PORTNAME} PYTHON_CMD=${PYTHON_CMD}
SUB_FILES=	pkg-message
USE_RC_SUBR=	sabnzbd

PORTDOCS=	ABOUT.txt \
		COPYRIGHT.txt \
		INSTALL.txt \
		ISSUES.txt \
		README.txt

USERS=		_sabnzbd
GROUPS=		_sabnzbd

OPTIONS_DEFINE=	PAR2CMDLINE UNRAR 7ZIP FEEDPARSER YENC OPENSSL DOCS
OPTIONS_DEFAULT=	PAR2CMDLINE UNRAR 7ZIP FEEDPARSER YENC OPENSSL
PAR2CMDLINE_DESC=	Required for postprocessing of par files
UNRAR_DESC=	Often required for unpacking many downloads
7ZIP_DESC=	Needed for unpacking 7-Zip posts
FEEDPARSER_DESC=	rss-feed support
YENC_DESC=	yenc support

PAR2CMDLINE_RUN_DEPENDS=	par2repair:archivers/par2cmdline-tbb
FEEDPARSER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>=0:textproc/py-feedparser
YENC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yenc>=0:news/py-yenc
OPENSSL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl
UNRAR_RUN_DEPENDS=	unrar:archivers/unrar
7ZIP_RUN_DEPENDS=	7za:archivers/p7zip

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s:/usr/bin/python:${PYTHON_CMD}:g" \
		 ${WRKSRC}/SABnzbd.py
	@${REINPLACE_CMD} -e "s:%%DATADIR%%:'${DATADIR}':g" \
		 ${WRKSRC}/SABnzbd.py

# the NO_BUILD option stops execution after configure. This should really be
# post-build
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/SABnzbd.py ${STAGEDIR}${PREFIX}/bin
	${INSTALL} -d ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sabnzbd
	cd ${WRKSRC}/sabnzbd && ${COPYTREE_SHARE} \* ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sabnzbd
	${INSTALL} -d ${STAGEDIR}${DATADIR}
.for i in cherrypy gntp interfaces locale po tools util
	${MKDIR} ${STAGEDIR}${DATADIR}/${i}
	cd ${WRKSRC}/${i} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/${i}
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
