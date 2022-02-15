PORTNAME=	ssh-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7
CATEGORIES=	security

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	CLI tools that make SSH more convenient

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	vaporup
USE_PERL5=	run
SHEBANG_FILES=	ssh-*

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ssh-* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
