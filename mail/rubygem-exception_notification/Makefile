PORTNAME=	exception_notification
PORTVERSION=	4.5.0
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Exception notification for Rails apps

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionmailer52>=5.2<8:mail/rubygem-actionmailer52 \
		rubygem-activesupport52>=5.2<8:devel/rubygem-activesupport52

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
