# $FreeBSD$

PORTNAME=	sabnzbd
PORTVERSION=	0.7.16
CATEGORIES=	news
MASTER_SITES=	SF/${PORTNAME}plus/${PORTNAME}plus/${PORTVERSION}
DISTNAME=	SABnzbd-${PORTVERSION}-src

MAINTAINER=	joshruehlig@gmail.com
COMMENT=	A web-interface based binary newsgrabber in python, with nzb support

LICENSE=	GPLv2 GPLv3 PSFL CHERRYPY CONFIGOBJ FEEDPARSER GNTP JSON KRONOS LISTQUOTE MSGFMT PYNEWSLEECHER RARFILE RSSLIB SSMTPLIB
LICENSE_COMB=	multi

RUN_DEPENDS=	cheetah:${PORTSDIR}/devel/py-cheetah \
		${PYTHON_SITELIBDIR}/pythonutils/configobj.py:${PORTSDIR}/devel/py-utils \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

LICENSE_NAME_CHERRYPY=	CherryPy License
LICENSE_FILE_CHERRYPY=	${WRKSRC}/licenses/License-CherryPy.txt
LICENSE_PERMS_CHERRYPY=	auto-accept

LICENSE_NAME_CONFIGOBJ=	configobj License
LICENSE_FILE_CONFIGOBJ=	${WRKSRC}/licenses/License-configobj.txt
LICENSE_PERMS_CONFIGOBJ=	auto-accept

LICENSE_NAME_FEEDPARSER=	feedparser License
LICENSE_FILE_FEEDPARSER=	${WRKSRC}/licenses/License-feedparser.txt
LICENSE_PERMS_FEEDPARSER=	auto-accept

LICENSE_NAME_GNTP=	gntp License
LICENSE_FILE_GNTP=	${WRKSRC}/licenses/License-gntp.txt
LICENSE_PERMS_GNTP=	auto-accept

LICENSE_NAME_JSON=	json License
LICENSE_FILE_JSON=	${WRKSRC}/licenses/License-json.txt
LICENSE_PERMS_JSON=	auto-accept

LICENSE_NAME_KRONOS=	kronos License
LICENSE_FILE_KRONOS=	${WRKSRC}/licenses/License-kronos.txt
LICENSE_PERMS_KRONOS=	auto-accept

LICENSE_NAME_LISTQUOTE=	listquote License
LICENSE_FILE_LISTQUOTE=	${WRKSRC}/licenses/License-listquote.txt
LICENSE_PERMS_LISTQUOTE=	auto-accept

LICENSE_NAME_MSGFMT=	msgfmt License
LICENSE_FILE_MSGFMT=	${WRKSRC}/licenses/License-msgfmt.txt
LICENSE_PERMS_MSGFMT=	auto-accept

LICENSE_NAME_PYNEWSLEECHER=	pynewsleecher License
LICENSE_FILE_PYNEWSLEECHER=	${WRKSRC}/licenses/License-pynewsleecher.txt
LICENSE_PERMS_PYNEWSLEECHER=	auto-accept

LICENSE_NAME_RARFILE=	rarfile License
LICENSE_FILE_RARFILE=	${WRKSRC}/licenses/License-rarfile.txt
LICENSE_PERMS_RARFILE=	auto-accept

LICENSE_NAME_RSSLIB=	rsslib License
LICENSE_FILE_RSSLIB=	${WRKSRC}/licenses/License-rsslib.txt
LICENSE_PERMS_RSSLIB=	auto-accept

LICENSE_NAME_SSMTPLIB=	ssmtplib License
LICENSE_FILE_SSMTPLIB=	${WRKSRC}/licenses/License-ssmtplib.txt
LICENSE_PERMS_SSMTPLIB=	auto-accept

USE_PYTHON=	2.5+
USES=		gettext

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/SABnzbd-${PORTVERSION}
PLIST_SUB=	PORTNAME=${PORTNAME}
SUB_LIST+=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message
USE_RC_SUBR=	${PORTNAME}
CONFLICTS_INSTALL=	sabnzbdplus-*

USERS=		media
GROUPS=		media

OPTIONS_DEFINE=	PAR2CMDLINE UNRAR FEEDPARSER YENC OPENSSL UNZIP
OPTIONS_DEFAULT=	PAR2CMDLINE UNRAR FEEDPARSER YENC OPENSSL UNZIP
PAR2CMDLINE_DESC=	Required for postprocessing of par files
UNRAR_DESC=	Often required for unpacking many downloads
FEEDPARSER_DESC=	rss-feed support
YENC_DESC=	yenc support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPAR2CMDLINE}
RUN_DEPENDS+=	par2repair:${PORTSDIR}/archivers/par2cmdline-tbb
.endif

.if ${PORT_OPTIONS:MFEEDPARSER}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser
.endif

.if ${PORT_OPTIONS:MYENC}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_yenc.so:${PORTSDIR}/news/py-yenc
.endif

.if ${PORT_OPTIONS:MOPENSSL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl
.endif

.if ${PORT_OPTIONS:MUNRAR}
RUN_DEPENDS+=	unrar:${PORTSDIR}/archivers/unrar
.endif

.if ${PORT_OPTIONS:MUNZIP}
RUN_DEPENDS+=   unzip:${PORTSDIR}/archivers/unzip
.endif

do-install:
	${INSTALL} -d ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/SABnzbd
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/SABnzbd

.include <bsd.port.post.mk>
