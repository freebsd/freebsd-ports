PORTNAME=	aws-actionmailer-ses
PORTVERSION=	1.2.0
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Amazon Simple Email Service as an ActionMailer delivery method
WWW=		https://github.com/aws/aws-actionmailer-ses-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionmailer-gitlab>=7.1.0:mail/rubygem-actionmailer-gitlab \
		rubygem-aws-sdk-ses-gitlab>=1.50.0<2:devel/rubygem-aws-sdk-ses-gitlab \
		rubygem-aws-sdk-sesv2-gitlab>=1.34.0<2:devel/rubygem-aws-sdk-sesv2-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
