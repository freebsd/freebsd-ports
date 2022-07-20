PORTNAME=	terminal-table
PORTVERSION=	3.0.2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, feature rich ASCII table generation library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-unicode-display_width>=1.1.1<3:devel/rubygem-unicode-display_width

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	examples/examples_unicode.rb
ruby_OLD_CMD=	"/bin/env ruby"

.include <bsd.port.mk>
