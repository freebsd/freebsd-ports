# $FreeBSD$

PORTNAME=	hieracles
PORTVERSION=	0.1.5
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	mose@gandi.net
COMMENT=	CLI tool for Hiera parameters visualisation and analysis

LICENSE=	MIT

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/hc man/man1/hc.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/hc.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
