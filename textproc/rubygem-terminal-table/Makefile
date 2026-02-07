PORTNAME=	terminal-table
PORTVERSION=	4.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, feature rich ASCII table generation library
WWW=		https://github.com/tj/terminal-table

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-unicode-display_width>=1.1.1<4:devel/rubygem-unicode-display_width

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	examples/examples_unicode.rb

.include <bsd.port.mk>
