# Ports collection makefile for:	py-werkzeug
# Date created:				12 January 2010
# Whom:					Moggie <moggie@elasticmind.net>
#
# $FreeBSD$
#

PORTNAME=	werkzeug
PORTVERSION=	0.6.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Werkzeug-${DISTVERSION}

MAINTAINER=	moggie@elasticmind.net
COMMENT=	Python utilities collection for building WSGI applications

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Werkzeug
PYDISTUTILS_PKGVERSION=	${DISTVERSION}
PYDISTUTILS_NOEGGINFO=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
