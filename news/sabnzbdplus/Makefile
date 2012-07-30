# New ports collection makefile for:   sabnzdbplus
# Date created:				January 2008
# Whom:					Daniel Bretoi
#
# $FreeBSD$
#

PORTNAME=	sabnzbdplus
PORTVERSION=	0.7.2
CATEGORIES=	news
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	SABnzbd-${PORTVERSION}-src

MAINTAINER=	dab@rj45.org
COMMENT=	A web-interface based binary newsgrabber in python, with nzb support

LICENSE=	GPLv2 GPLv3 PSFL CHERRYPY CONFIGOBJ FEEDPARSER GNTP JSON KRONOS LISTQUOTE MSGFMT PYNEWSLEECHER RARFILE RSSLIB SSMTPLIB
LICENSE_COMB=	multi

RUN_DEPENDS=	cheetah:${PORTSDIR}/devel/py-cheetah \
		${PYTHON_SITELIBDIR}/pythonutils/configobj.py:${PORTSDIR}/devel/py-utils \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

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
USE_GETTEXT=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/SABnzbd-${PORTVERSION}
PLIST_SUB=	PORTNAME=${PORTNAME}
SUB_LIST+=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message
USE_RC_SUBR=	sabnzbd
CONFLICTS_INSTALL=	sabzndb-0.*

PORTDOCS=	ABOUT.txt \
		CHANGELOG.txt \
		COPYRIGHT.txt \
		INSTALL.txt \
		ISSUES.txt \
		README.txt

USERS=		_sabnzbd
GROUPS=		_sabnzbd

OPTIONS_DEFINE=	PAR2CMDLINE UNRAR FEEDPARSER YENC OPENSSL
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
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl
.endif

.if ${PORT_OPTIONS:MYENC}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_yenc.so:${PORTSDIR}/news/py-yenc
.endif

.if ${PORT_OPTIONS:MOPENSSL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser
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
	${INSTALL_SCRIPT} ${WRKSRC}/SABnzbd.py ${PREFIX}/bin
	${INSTALL} -d ${PYTHONPREFIX_SITELIBDIR}/sabnzbd
	cd ${WRKSRC}/sabnzbd && ${COPYTREE_SHARE} \* ${PYTHONPREFIX_SITELIBDIR}/sabnzbd
	${INSTALL} -d ${DATADIR}
.for i in cherrypy gntp interfaces locale po tools util
	${MKDIR} ${DATADIR}/${i}
	cd ${WRKSRC}/${i} && ${COPYTREE_SHARE} \* ${DATADIR}/${i}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	${MKDIR} ${PREFIX}/sabnzbd
	${CHOWN} _sabnzbd:_sabnzbd ${PREFIX}/sabnzbd
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
