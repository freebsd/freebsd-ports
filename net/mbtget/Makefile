PORTNAME=	mbtget
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	net

MAINTAINER=	ing.castellanosdz@gmail.com
COMMENT=	Simple Modbus/TCP client CLI tool
WWW=		https://github.com/sourceperl/mbtget/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	sourceperl
USE_PERL5=	run

SHEBANG_FILES=	scripts/mbtget

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/mbtget

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mbtget ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
