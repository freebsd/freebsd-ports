PORTNAME=	actioncable
PORTVERSION=	8.0.2.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	80

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Structure many real-time application concerns into channels over a single WebSocket connection
WWW=		https://github.com/rails/rails/tree/main/actioncable \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack80>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack80 \
		rubygem-activesupport80>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport80 \
		rubygem-nio4r>=2.0<3:devel/rubygem-nio4r \
		rubygem-websocket-driver>=0.6.1:www/rubygem-websocket-driver \
		rubygem-zeitwerk>=2.6<3:devel/rubygem-zeitwerk

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^8\.0\.

.include <bsd.port.mk>
