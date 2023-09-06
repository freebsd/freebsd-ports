PORTNAME=	premailer-rails
PORTVERSION=	1.10.3
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	110-rails70

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Improve the rendering of HTML emails
WWW=		https://github.com/fphilipe/premailer-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionmailer70>=3:mail/rubygem-actionmailer70 \
		rubygem-net-smtp>=0:mail/rubygem-net-smtp \
		rubygem-premailer>=1.7.9<2:mail/rubygem-premailer

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.10\.

.include <bsd.port.mk>
