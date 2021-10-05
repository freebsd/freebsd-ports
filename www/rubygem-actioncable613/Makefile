# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	actioncable
PORTVERSION=	6.1.3.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	613

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Integrated WebSockets for Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack613>=${PORTVERSION}:www/rubygem-actionpack613 \
		rubygem-activesupport613>=${PORTVERSION}:devel/rubygem-activesupport613 \
		rubygem-nio4r>=2.0<3:devel/rubygem-nio4r \
		rubygem-websocket-driver>=0.6.1:www/rubygem-websocket-driver

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
