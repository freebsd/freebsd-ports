PORTNAME=	rails-html-sanitizer
PORTVERSION=	1.5.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sanitize HTML fragments in Rails applications
WWW=		https://github.com/rails/rails-html-sanitizer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-loofah>=2.19.1<3:textproc/rubygem-loofah

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	html_sanitizer

.include <bsd.port.mk>
