# Created by: Thomas Zander <riggs@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	pftables
PORTVERSION=	0.1
CATEGORIES=	sysutils

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Minimal rc script to save and restore pf tables upon reboots

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	riggs-
GH_COMMIT=	6a29e7a
GH_TAGNAME=	${GH_COMMIT}

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	etc/rc.d/pftables

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pftables ${STAGEDIR}${PREFIX}/etc/rc.d

.include <bsd.port.mk>
