PORTNAME=	sinatra-r18n
PORTVERSION=	5.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sinatra extension that provides i18n support to your web application

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-r18n-core>=5.0<6:devel/rubygem-r18n-core \
		rubygem-sinatra>=1.3<3:www/rubygem-sinatra

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
