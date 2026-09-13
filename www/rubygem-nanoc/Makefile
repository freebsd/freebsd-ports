PORTNAME=	nanoc
DISTVERSION=	4.12.15
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Simple but flexible static site generator
WWW=		https://nanoc.ws/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.5<3:www/rubygem-addressable \
		rubygem-colored>=1.2<2:textproc/rubygem-colored \
		rubygem-nanoc-checking>=1.0.2<2:www/rubygem-nanoc-checking \
		rubygem-nanoc-cli=4.12.15:www/rubygem-nanoc-cli \
		rubygem-nanoc-core=4.12.15:www/rubygem-nanoc-core \
		rubygem-nanoc-deploying>=1.0<2:www/rubygem-nanoc-deploying \
		rubygem-parallel1>=1.12<2:sysutils/rubygem-parallel1 \
		rubygem-tty-command>=0.8<1:devel/rubygem-tty-command \
		rubygem-tty-which>=0.4<1:devel/rubygem-tty-which

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/nanoc

.include <bsd.port.mk>
