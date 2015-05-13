# $FreeBSD$

PORTNAME=	sabnzbdplus
PORTVERSION=	0.7.20
CATEGORIES=	news
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	SABnzbd-${PORTVERSION}-src

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Web-interface based binary newsgrabber in python, with nzb support

LICENSE=	BSD2CLAUSE BSD3CLAUSE GPLv2 GPLv3 ISCL MIT PSFL
LICENSE_COMB=	multi

RUN_DEPENDS=	cheetah:${PORTSDIR}/devel/py-cheetah \
		${PYTHON_SITELIBDIR}/pythonutils/configobj.py:${PORTSDIR}/devel/py-utils \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

USES=		gettext python

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/SABnzbd-${PORTVERSION}
PLIST_SUB=	PORTNAME=${PORTNAME}
SUB_LIST+=	PORTNAME=${PORTNAME} PYTHON_CMD=${PYTHON_CMD}
SUB_FILES=	pkg-message
USE_RC_SUBR=	sabnzbd

PORTDOCS=	ABOUT.txt \
		CHANGELOG.txt \
		COPYRIGHT.txt \
		INSTALL.txt \
		ISSUES.txt \
		README.txt

USERS=		_sabnzbd
GROUPS=		_sabnzbd

OPTIONS_DEFINE=	PAR2CMDLINE UNRAR FEEDPARSER YENC OPENSSL DOCS
OPTIONS_DEFAULT=	PAR2CMDLINE UNRAR FEEDPARSER YENC OPENSSL
PAR2CMDLINE_DESC=	Required for postprocessing of par files
UNRAR_DESC=	Often required for unpacking many downloads
FEEDPARSER_DESC=	rss-feed support
YENC_DESC=	yenc support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPAR2CMDLINE}
RUN_DEPENDS+=	par2repair:${PORTSDIR}/archivers/par2cmdline-tbb
.endif

.if ${PORT_OPTIONS:MFEEDPARSER}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}feedparser>=0:${PORTSDIR}/textproc/py-feedparser
.endif

.if ${PORT_OPTIONS:MYENC}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}yenc>=0:${PORTSDIR}/news/py-yenc
.endif

.if ${PORT_OPTIONS:MOPENSSL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}openssl>=0:${PORTSDIR}/security/py-openssl
.endif

.if ${PORT_OPTIONS:MUNRAR}
RUN_DEPENDS+=	unrar:${PORTSDIR}/archivers/unrar
.endif

post-patch:
	@${REINPLACE_CMD} -e "s:/usr/bin/python:${PYTHON_CMD}:g" \
		 ${WRKSRC}/SABnzbd.py
	@${REINPLACE_CMD} -e "s:%%PREFIX%%:'${DATADIR}':g" \
		 ${WRKSRC}/SABnzbd.py

# the NO_BUILD option stops execution after configure. This should really be
# post-build
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/SABnzbd.py ${STAGEDIR}${PREFIX}/bin
	${INSTALL} -d ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sabnzbd
	cd ${WRKSRC}/sabnzbd && ${COPYTREE_SHARE} \* ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sabnzbd
	${INSTALL} -d ${STAGEDIR}${DATADIR}
	${INSTALL} -d ${STAGEDIR}${PREFIX}/sabnzbd
.for i in cherrypy gntp interfaces locale po tools util
	${MKDIR} ${STAGEDIR}${DATADIR}/${i}
	cd ${WRKSRC}/${i} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/${i}
.endfor

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
