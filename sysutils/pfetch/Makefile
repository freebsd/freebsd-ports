# $FreeBSD$

PORTNAME=	pfetch
DISTVERSION=	0.6.0
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Pretty system information tool written in POSIX sh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USE_GITHUB=	yes
GH_ACCOUNT=	dylanaraps

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
