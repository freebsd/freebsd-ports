# $FreeBSD$

PORTNAME=	pchecker
PORTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	ak-various-projects

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Tool that checks the ports tree for various errors

LICENSE=	BSD

USE_XZ=	yes
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
