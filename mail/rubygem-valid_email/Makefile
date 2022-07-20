PORTNAME=	valid_email
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	ActiveModel Validation for email

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel61>=0:databases/rubygem-activemodel61 \
		rubygem-mail>=2.6.1:mail/rubygem-mail \
		rubygem-simpleidn>=0:dns/rubygem-simpleidn

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
