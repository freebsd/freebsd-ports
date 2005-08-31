# New ports collection makefile for:	svnmailer
# Date created:		2005-08-30
# Whom:			Andrej Zverev <az@inec.ru>
#
# $FreeBSD$
#

PORTNAME=	svnmailer
PORTVERSION=	1.0.5
CATEGORIES=	mail python
MASTER_SITES=	http://storage.perlig.de/${PORTNAME}/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	az@inec.ru
COMMENT=	A tool to post subversion repository commit information

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libsvn/__init__.py:${PORTSDIR}/devel/subversion-python

USE_PYTHON=		2.3+
USE_PYDISTUTILS=	yes
USE_REINPLACE=		yes

PORTDOCS=	index.html perlig.css perlig.jpg perlig_docs.css \
		perlig_offline.css right.gif up.gif

post-patch:
	@${REINPLACE_CMD} -e "1s|^.*|#!${PYTHON_CMD}|" ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "1s|^.*|#!${PYTHON_CMD}|" ${WRKSRC}/src/svn-mailer

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
