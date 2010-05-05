# New ports collection makefile for: trac-gantt
# Date created:                      July 12 2006
# Whom:                              Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	TracGantt
PORTVERSION=	0.3.2a
PORTREVISION=	4
CATEGORIES=	www devel python
MASTER_SITES=	http://willbarton.com/files/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMEPREFIX=	trac-

MAINTAINER=	dryice@dryice.name
COMMENT=	A plugin to creates Gantt charts for trac

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	trac>=0.11:${PORTSDIR}/www/trac

NO_BUILD=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION} PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	PKG-INFO README
.endif

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
