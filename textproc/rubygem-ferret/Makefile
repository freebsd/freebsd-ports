PORTNAME=	ferret
PORTVERSION=	0.11.8.7
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby port of Lucene
WWW=		https://github.com/jkraemer/ferret

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

DEPRECATED=	Broken with all supported Ruby versions
EXPIRATION_DATE=	2023-06-30
BROKEN_aarch64=	fails to build: cannot determine target CPU
BROKEN_riscv64=	fails to build: cannot determine target CPU
BROKEN_RUBY30=	yes
BROKEN_RUBY31=	yes
BROKEN_RUBY32=	yes
BROKEN_RUBY33=	yes

USES=		gem

PLIST_FILES=	bin/ferret-browser

.include <bsd.port.mk>
