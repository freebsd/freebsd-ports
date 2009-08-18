# New ports collection makefile for:	py-punjab
# Date created:		17 February 2006
# Whom:			jodocus <jodocus@jodocus.org>
#
# $FreeBSD$
#

PORTNAME=	punjab
PORTVERSION=	0.12
CATEGORIES=	net-im python
MASTER_SITES=	http://butterfat.net/punjab/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	beech@FreeBSD.org
COMMENT=	HTTP-polling and HTTP-binding gateway for Jabber

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
USE_TWISTED=	words web conch names

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/SOAPpy/__init__.py:${PORTSDIR}/net/py-soappy

PORTDOCS=	README.txt INSTALL.txt NOTES.txt PKG-INFO

USE_RC_SUBR=	punjab.sh
SUB_LIST+=	"PYTHON_CMD=${PYTHONBASE}/bin/${PYTHON_VERSION}"

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

post-install:
	@${INSTALL} -d ${WWWDIR}
	@${CAT} ${PKGMESSAGE}

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.if !defined(NOPORTEXAMPLES)
	@cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
PLIST_SUB+=	PORTEXAMPLES=""
.else
PLIST_SUB+=	PORTEXAMPLES="@comment "
.endif

.include <bsd.port.post.mk>
