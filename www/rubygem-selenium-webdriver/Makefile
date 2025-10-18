PORTNAME=	selenium-webdriver
PORTVERSION=	4.36.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for writing automated tests of websites
WWW=		https://www.seleniumhq.org/ \
		https://github.com/SeleniumHQ/selenium/tree/trunk/rb

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-base64>=0.2<1:converters/rubygem-base64 \
		rubygem-json>=2.15.0<2.16:devel/rubygem-json \
		rubygem-logger>=1.4<2:devel/rubygem-logger \
		rubygem-prism>=1.0<2:textproc/rubygem-prism \
		rubygem-rexml>=3.2.5<4:textproc/rubygem-rexml \
		rubygem-rubyzip>=1.2.2<4.0:archivers/rubygem-rubyzip \
		rubygem-websocket>=1.0<2:www/rubygem-websocket

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
