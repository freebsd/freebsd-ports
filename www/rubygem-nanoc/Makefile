PORTNAME=	nanoc
DISTVERSION=	4.12.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Simple but flexible static site generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.5:www/rubygem-addressable \
		rubygem-colored>=1.2:textproc/rubygem-colored \
		rubygem-nanoc-checking>=1.0:www/rubygem-nanoc-checking \
		rubygem-nanoc-cli=4.12.5:www/rubygem-nanoc-cli \
		rubygem-nanoc-core=4.12.5:www/rubygem-nanoc-core \
		rubygem-nanoc-deploying>=1.0:www/rubygem-nanoc-deploying \
		rubygem-parallel>=1.12:sysutils/rubygem-parallel \
		rubygem-tty-command>=0.8:devel/rubygem-tty-command \
		rubygem-tty-which>=0.4:devel/rubygem-tty-which

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/nanoc

.include <bsd.port.mk>
