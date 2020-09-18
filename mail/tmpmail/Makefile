# $FreeBSD$

PORTNAME=	tmpmail
DISTVERSION=	1.0.3
CATEGORIES=	mail

MAINTAINER=	se@FreeBSD.org
COMMENT=	CLI for the creation and use of temporary mail addresses

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		w3m:www/w3m \
		curl:ftp/curl \
		jq:textproc/jq

NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sdushantha
GH_TAGNAME=	39d0bac

PLIST_FILES=	bin/tmpmail

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/tmpmail ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
