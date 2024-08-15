PORTNAME=	pfetch
DISTVERSION=	1.3.0
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Pretty system information tool written in POSIX sh
WWW=		https://github.com/Un1q32/pfetch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Un1q32

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
