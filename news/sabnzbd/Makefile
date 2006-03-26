# New ports collection makefile for:	sabnzbd
# Date created:				16 March 2006
# Whom:					Daniel Bretoi
#
# $FreeBSD$
#

PORTNAME=	SABnzbd
PORTVERSION=	0.1.8.1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sabnzbd

MAINTAINER=	daniel@netwalk.org
COMMENT=	A web-interface based binary newsgrabber in python, with nzb support

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	cheetah:${PORTSDIR}/devel/py-cheetah \
		${PYTHON_SITELIBDIR}/cherrypy/__init__.py:${PORTSDIR}/www/py-cherrypy \
		${PYTHON_SITELIBDIR}/pythonutils/configobj.py:${PORTSDIR}/devel/py-utils \
		${PYTHON_SITELIBDIR}/cElementTree.so:${PORTSDIR}/devel/py-celementtree

USE_PYTHON=	2.4
USE_PYDISTUTILS=yes

PLIST_SUB=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message

OPTIONS=	PAR2CMDLINE "Required for postprocessing of par files." on \
		UNRAR "Often required for unpacking many downloads." on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PAR2CMDLINE)
RUN_DEPENDS+=	par2repair:${PORTSDIR}/archivers/par2cmdline
.endif

.if !defined(WITHOUT_UNRAR)
RUN_DEPENDS+=	unrar:${PORTSDIR}/archivers/unrar
.endif

post-install:
	${CHMOD} -R go+r ${PREFIX}/share/${PORTNAME}/
	${CHMOD} -R go+r ${PREFIX}/share/doc/${PORTNAME}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
