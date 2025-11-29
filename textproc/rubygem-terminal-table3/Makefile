PORTNAME=	terminal-table
PORTVERSION=	3.0.2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, feature rich ASCII table generation library
WWW=		https://github.com/tj/terminal-table

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-unicode-display_width2>=1.1.1<3:devel/rubygem-unicode-display_width2

USES=		gem shebangfix

NO_ARCH=	yes

PORTSCOUT=	limit:^3\.

SHEBANG_FILES=	examples/examples_unicode.rb

.include <bsd.port.mk>
