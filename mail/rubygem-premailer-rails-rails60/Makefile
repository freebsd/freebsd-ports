# Created by: Torsten Zuehlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	premailer-rails
PORTVERSION=	1.10.3
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails60

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Improve the rendering of HTML emails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionmailer60>=3:mail/rubygem-actionmailer60 \
		rubygem-premailer>=1.7.9<2:mail/rubygem-premailer

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
