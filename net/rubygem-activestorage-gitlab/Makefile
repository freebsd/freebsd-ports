PORTNAME=	activestorage
PORTVERSION=	${RAILS_VERSION}
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Attach cloud and local files in Rails applications
WWW=		https://github.com/rails/rails/tree/main/activestorage \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack-gitlab>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack-gitlab \
		rubygem-activejob-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob-gitlab \
		rubygem-activerecord-gitlab>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord-gitlab \
		rubygem-activesupport-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport-gitlab \
		rubygem-marcel-gitlab>=1.0<2:devel/rubygem-marcel-gitlab

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.1\.

.include "${.CURDIR}/../../www/gitlab/Makefile.common"
.include <bsd.port.mk>
