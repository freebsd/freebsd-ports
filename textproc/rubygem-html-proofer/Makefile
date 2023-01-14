PORTNAME=	html-proofer
PORTVERSION=	4.4.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test your rendered HTML files
WWW=		https://github.com/gjtorikian/html-proofer

LICENSE=	MIT

RUN_DEPENDS=	rubygem-addressable>=2.3<3:www/rubygem-addressable \
		rubygem-mercenary>=0.3<1:devel/rubygem-mercenary \
		rubygem-nokogiri>=1.13<2:textproc/rubygem-nokogiri \
		rubygem-parallel>=1.10<2:sysutils/rubygem-parallel \
		rubygem-rainbow>=3.0<4:devel/rubygem-rainbow \
		rubygem-typhoeus>=1.3<2:www/rubygem-typhoeus \
		rubygem-yell>=2.0<3:sysutils/rubygem-yell \
		rubygem-zeitwerk>=2.5<3:devel/rubygem-zeitwerk

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/htmlproofer

# html-proofer 5+ requires async 2.1.0+ which requires Ruby 3.1+
# Update to 5.* after Ruby 3.1 becomes the default version
PORTSCOUT=	limit:^4\.

.include <bsd.port.mk>
