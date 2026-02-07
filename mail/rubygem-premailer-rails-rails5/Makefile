PORTNAME=	premailer-rails
PORTVERSION=	1.12.0
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Improve the rendering of HTML emails
WWW=		https://github.com/fphilipe/premailer-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionmailer5>=3:mail/rubygem-actionmailer5 \
		rubygem-net-smtp>=0:mail/rubygem-net-smtp \
		rubygem-premailer>=1.7.9<2:mail/rubygem-premailer

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
