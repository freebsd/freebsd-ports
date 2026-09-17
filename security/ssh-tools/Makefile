PORTNAME=	ssh-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9
CATEGORIES=	security
MASTER_SITES=	https://codeberg.org/vaporup/ssh-tools/archive/
DISTNAME=	${DISTVERSIONFULL}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	CLI tools that make SSH more convenient
WWW=		https://codeberg.org/vaporup/ssh-tools

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_GLOB=	ssh-*

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cmd/bash/*/ssh-* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
