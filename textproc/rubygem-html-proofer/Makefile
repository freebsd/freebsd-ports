# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	html-proofer
PORTVERSION=	3.19.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test your rendered HTML files

LICENSE=	MIT

RUN_DEPENDS=	rubygem-addressable>=2.3<3:www/rubygem-addressable \
		rubygem-mercenary>=0.3<1:devel/rubygem-mercenary \
		rubygem-nokogiri>=1.12<2:textproc/rubygem-nokogiri \
		rubygem-parallel>=1.3<2:sysutils/rubygem-parallel \
		rubygem-rainbow>=3.0<4:devel/rubygem-rainbow \
		rubygem-typhoeus>=1.3<2:www/rubygem-typhoeus \
		rubygem-yell>=2.0<3:sysutils/rubygem-yell

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/htmlproofer

.include <bsd.port.mk>
