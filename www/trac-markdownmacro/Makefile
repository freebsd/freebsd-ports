PORTNAME=	markdownmacro
PORTVERSION=	0.11.10r${REV}
PORTREVISION=	3
CATEGORIES=	www devel python
# trac-hacks.org now allows only browser based download, so using my mirror
MASTER_SITES=	https://bsd.samm.cz/markdownmacro/
PKGNAMEPREFIX=	trac-

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Table of contents macro for Trac
WWW=		https://trac-hacks.org/wiki/TocMacro

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac \
		${PYTHON_PKGNAMEPREFIX}markdown>=0:textproc/py-markdown@${PY_FLAVOR}

REV=			18423
DISTFILES=		markdownmacro-${REV}.zip
WRKSRC=			${WRKDIR}/markdownmacro/trunk
USES=			python zip
USE_PYTHON=		distutils autoplist
NO_ARCH=		yes

.include <bsd.port.mk>
