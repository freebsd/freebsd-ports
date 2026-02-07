PORTNAME=	bsdebfetch
DISTVERSION=	1.1-bsd
CATEGORIES=	sysutils
MASTER_SITES=	https://git.sr.ht/~shiorid/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	ports@shiori.com.br
COMMENT=	Simple system info tool written in bash
WWW=		https://git.sr.ht/~shiorid/bsdebfetch

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/bsdebfetch \
		share/man/man1/bsdebfetch.1.gz

.include <bsd.port.mk>
