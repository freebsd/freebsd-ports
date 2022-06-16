PORTNAME=	rails-html-sanitizer
PORTVERSION=	1.4.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sanitize HTML fragments in Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-loofah>=2.3<3:textproc/rubygem-loofah

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	html_sanitizer

.include <bsd.port.mk>
