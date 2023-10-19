PORTNAME=	unitc
PORTVERSION=	${UNIT_VERSION}
CATEGORIES=	www
MASTER_SITES?=	https://unit.nginx.org/download/
DISTNAME=	unit-${PORTVERSION}
DISTINFO_FILE=	${.CURDIR}/../../www/unit/distinfo

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Command-line management tool for NGINX Unit
WWW=		https://unit.nginx.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash>0:shells/bash \
		curl:ftp/curl

CPE_VENDOR=	nginx
CPE_PRODUCT=	unit

USES+=		cpe shebangfix
SHEBANG_FILES=	tools/unitc

NO_BUILD=	yes

PLIST_FILES?=	bin/unitc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/unitc ${STAGEDIR}${PREFIX}/bin/

.include "../../www/unit/version.mk"
.include <bsd.port.mk>
