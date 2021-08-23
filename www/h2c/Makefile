PORTNAME=	h2c
DISTVERSION=	1.0
CATEGORIES=	www

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Provided a set of HTTP request headers, output a curl command line

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	curl
USE_PERL5=	run
SHEBANG_FILES=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
