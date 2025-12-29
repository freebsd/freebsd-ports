PORTNAME=	tocmacro
PORTVERSION=	12.0.0r${REV}
PORTREVISION=	3
CATEGORIES=	www devel python
# trac-hacks.org now allows only browser based download, so using my mirror
MASTER_SITES=	https://bsd.samm.cz/tocmacro/

PKGNAMEPREFIX=	trac-

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Table of contents macro for Trac
WWW=		https://trac-hacks.org/wiki/TocMacro

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac

REV=			18149
DISTFILES=		0.11-${REV}.zip
WRKSRC=			${WRKDIR}/0.11
USES=			python zip
USE_PYTHON=		distutils autoplist
NO_ARCH=		yes

.include <bsd.port.mk>
