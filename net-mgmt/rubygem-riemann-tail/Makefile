# $FreeBSD$

PORTNAME=	riemann-tail
DISTVERSION=	0.0.1
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Tail Riemann event streams from the console

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-colorize>=0:devel/rubygem-colorize \
		rubygem-faye-websocket>=0:www/rubygem-faye-websocket \
		rubygem-thor>=0:devel/rubygem-thor

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTDOCS=	README.md

PLIST_FILES=	bin/riemann-tail

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
