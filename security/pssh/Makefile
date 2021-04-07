PORTNAME=	pssh
PORTVERSION=	2.3.4
DISTVERSIONPREFIX=	v
CATEGORIES=	security net sysutils

MAINTAINER=	timp87@gmail.com
COMMENT=	Parallel version of OpenSSH and related tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rsync:net/rsync

USES=		python:3.5+
USE_GITHUB=	yes
GH_ACCOUNT=	lilydjwg
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
.include <bsd.port.mk>
