# $FreeBSD$

PORTNAME=	gntp
PORTVERSION=	0.8
#PORTREVISION=	0
CATEGORIES=	net
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Growl Notification Transport Protocol for Python

LICENSE=	MIT

GH_ACCOUNT=	kfdm
GH_COMMIT=	a4c1c69
GH_TAGNAME=	v${PORTVERSION}

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PYDISTUTILS_BUILD_TARGET+=	build_sphinx

post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/build/sphinx/html && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
