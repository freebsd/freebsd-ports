PORTNAME=	ferret
PORTVERSION=	0.11.8.7
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby port of Lucene

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

BROKEN_aarch64=	fails to build: cannot determine target CPU
BROKEN_riscv64=	fails to build: cannot determine target CPU
BROKEN_RUBY30=	yes
BROKEN_RUBY31=	yes

USES=		gem
USE_RUBY=	yes

PLIST_FILES=	bin/ferret-browser

.include <bsd.port.mk>
