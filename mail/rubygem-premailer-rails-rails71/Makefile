PORTNAME=	premailer-rails
PORTVERSION=	1.12.0
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails71

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CSS styled emails without the hassle
WWW=		https://github.com/fphilipe/premailer-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionmailer71>=3:mail/rubygem-actionmailer71 \
		rubygem-net-smtp>=0:mail/rubygem-net-smtp \
		rubygem-premailer>=1.7.9<2:mail/rubygem-premailer

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
