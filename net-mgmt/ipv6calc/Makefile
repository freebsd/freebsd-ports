PORTNAME=	ipv6calc
PORTVERSION=	4.3.3
CATEGORIES=	net-mgmt

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convert, change, and calculate with IPv6 addresses
WWW=		https://www.deepspace6.net/projects/ipv6calc.html \
		https://github.com/pbiering/ipv6calc

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash

USES=		gmake perl5 shebangfix ssl

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pbiering

SHEBANG_FILES=	tools/*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
