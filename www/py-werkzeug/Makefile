# Created by: Moggie <moggie@elasticmind.net>
# $FreeBSD$
#

PORTNAME=	werkzeug
PORTVERSION=	0.9.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Werkzeug-${DISTVERSION}

MAINTAINER=	moggie@elasticmind.net
COMMENT=	Python utilities collection for building WSGI applications

LICENSE=	BSD

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Werkzeug
PYDISTUTILS_PKGVERSION=	${DISTVERSION}
PYDISTUTILS_NOEGGINFO=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.include <bsd.port.post.mk>
