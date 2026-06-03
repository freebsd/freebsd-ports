PORTNAME=	accountmanager
PORTVERSION=	0.6.${REV}
PORTREVISION=	3
CATEGORIES=	www devel python
# trac-hacks.org now allows only browser based download, so using my mirror
MASTER_SITES=	https://bsd.samm.cz/accountmanagerplugin/
PKGNAMEPREFIX=	trac-
DISTFILES=	trunk-${REV}.zip

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Account Manager Plugin for trac
WWW=		https://trac-hacks.org/wiki/AccountManagerPlugin

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac

REV=			18669
WRKSRC=			${WRKDIR}/trunk
USES=			python zip
USE_PYTHON=		distutils autoplist
NO_ARCH=		yes

.include <bsd.port.mk>
