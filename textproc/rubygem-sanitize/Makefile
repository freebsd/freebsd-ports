PORTNAME=	sanitize
PORTVERSION=	6.1.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Whitelist based HTML sanitizer
WWW=		https://github.com/rgrove/sanitize

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-crass>=1.0.2<1.1:www/rubygem-crass \
		rubygem-nokogiri>=1.12.0:textproc/rubygem-nokogiri

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	sanitize_project

.include <bsd.port.mk>
