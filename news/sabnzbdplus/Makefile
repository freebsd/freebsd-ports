# New ports collection makefile for:   sabnzdbplus
# Date created:				January 2008
# Whom:					Daniel Bretoi
#
# $FreeBSD$
#

PORTNAME=	sabnzbdplus
PORTVERSION=	0.5.6
PORTREVISION=	2
CATEGORIES=	news
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/sabnzbd-${PORTVERSION}
DISTNAME=	SABnzbd-${PORTVERSION}-src

MAINTAINER=	daniel@netwalk.org
COMMENT=	A web-interface based binary newsgrabber in python, with nzb support

RUN_DEPENDS=	cheetah:${PORTSDIR}/devel/py-cheetah \
		${PYTHON_PKGNAMEPREFIX}cherrypy>=3.2.0:${PORTSDIR}/www/py-cherrypy \
		${PYTHON_SITELIBDIR}/pythonutils/configobj.py:${PORTSDIR}/devel/py-utils \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

LICENSE=	GPLv2

USE_PYTHON=	2.5+

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/SABnzbd-${PORTVERSION}
PLIST_SUB=	PORTNAME=${PORTNAME}
SUB_LIST+=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message
USE_RC_SUBR=	sabnzbd
CONFLICTS=	sabzndb-0.*

USERS=		_sabnzbd
GROUPS=		_sabnzbd

OPTIONS=	PAR2CMDLINE "Required for postprocessing of par files." on \
		UNRAR "Often required for unpacking many downloads." on \
		FEEDPARSER "rss-feed support." on \
		YENC "yenc support." on \
		OPENSSL "SSL support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PAR2CMDLINE)
RUN_DEPENDS+=	par2repair:${PORTSDIR}/archivers/par2cmdline
.endif

.if !defined(WITHOUT_FEEDPARSER)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl
.endif

.if !defined(WITHOUT_YENC)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_yenc.so:${PORTSDIR}/news/py-yenc
.endif

.if !defined(WITHOUT_OPENSSL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser
.endif

.if !defined(WITHOUT_UNRAR)
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
	${INSTALL_SCRIPT} ${WRKSRC}/SABnzbd.py ${PREFIX}/bin/SABnzbd.py
	${INSTALL} -d  ${PYTHONPREFIX_SITELIBDIR}/
	${CP} -rp ${WRKSRC}/sabnzbd ${PYTHONPREFIX_SITELIBDIR}/
	${INSTALL} -d ${DATADIR}
	${CP} -rp ${WRKSRC}/interfaces ${DATADIR}
	${CP} -rp ${WRKSRC}/language ${DATADIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in CHANGELOG.txt INSTALL.txt ISSUES.txt LICENSE.txt README.txt
	${CP} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif
	${MKDIR} ${PREFIX}/sabnzbd
	${CHOWN} _sabnzbd:_sabnzbd ${PREFIX}/sabnzbd
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
