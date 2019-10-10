# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	leproxy
PORTVERSION=	0.2.2
CATEGORIES=	net
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${PORTVERSION}/
EXTRACT_SUFX=	.php
EXTRACT_ONLY=	# empty

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	HTTP/SOCKS proxy server for everybody

LICENSE=	MIT

USES=		php
USE_PHP=	filter

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}.php

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTFILES} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}.php

.include <bsd.port.mk>
