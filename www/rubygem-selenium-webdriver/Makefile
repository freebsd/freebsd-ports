PORTNAME=	selenium-webdriver
PORTVERSION=	4.6.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for writing automated tests of websites
WWW=		https://www.seleniumhq.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-childprocess>=0.5<5.0:devel/rubygem-childprocess \
		rubygem-rexml>=3.2.5<4:textproc/rubygem-rexml \
		rubygem-rubyzip>=1.2.2<3.0:archivers/rubygem-rubyzip \
		rubygem-websocket>=1.0<2:www/rubygem-websocket

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
