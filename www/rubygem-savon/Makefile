PORTNAME=	savon
PORTVERSION=	2.15.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Library for SOAP communications
WWW=		https://github.com/savonrb/savon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-akami>=1.2:www/rubygem-akami \
		rubygem-builder>=2.1.2:devel/rubygem-builder \
		rubygem-gyoku>=1.2:devel/rubygem-gyoku \
		rubygem-httpi>=4.0:www/rubygem-httpi \
		rubygem-mail>2.5:mail/rubygem-mail \
		rubygem-nokogiri>=1.8.1:textproc/rubygem-nokogiri \
		rubygem-nori>=2.4:devel/rubygem-nori \
		rubygem-wasabi>=3.7:www/rubygem-wasabi

NO_ARCH=	yes
USES=		gem

.include <bsd.port.mk>
