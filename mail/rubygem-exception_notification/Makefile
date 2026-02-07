PORTNAME=	exception_notification
PORTVERSION=	5.0.1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Exception notification for Rails apps
WWW=		https://github.com/kmcphillips/exception_notification

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionmailer80>=7.1<9:mail/rubygem-actionmailer80 \
		rubygem-activesupport80>=7.1<9:devel/rubygem-activesupport80

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
